
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation, rc

def traslacion(dx, dy, dz):
    return np.array([[1, 0, 0, dx], 
                     [0, 1, 0, dy], 
                     [0, 0, 1, dz], 
                     [0, 0, 0,  1]]).T
                     
def rotacion(ang):
    c = np.cos(ang)
    s = np.sin(ang)
    return np.array([[c, -s, 0, 0], 
                     [s,  c, 0, 0], 
                     [0,  0, 1, 0], 
                     [0,  0, 0, 1]]).T

def rotacionX(ang):
    c = np.cos(ang)
    s = np.sin(ang)
    return np.array([[1, 0,  0, 0], 
                     [0, c, -s, 0], 
                     [0, s,  c, 0], 
                     [0, 0,  0, 1]]).T

def rotacionY(ang):
    c = np.cos(ang)
    s = np.sin(ang)
    return np.array([[c, 0, -s, 0], 
                     [0, 1,  0, 0], 
                     [s, 0,  c, 0], 
                     [0, 0,  0, 1]]).T

def rotacionZ(ang):
    c = np.cos(ang)
    s = np.sin(ang)
    return np.array([[c, -s, 0, 0], 
                     [s,  c, 0, 0], 
                     [0,  0, 1, 0], 
                     [0,  0, 0, 1]]).T

def rotate_figureX(c, mp, puntos):
    R = rotacionX(np.pi*c/60)
    P1 = np.matmul(mp, R)
    puntos.set_data(P1[:,0], P1[:,1])   
    return puntos

    
def rotate_figureY(c, mp, puntos):
    R = rotacionY(np.pi*c/60)
    P1 = np.matmul(mp, R)
    puntos.set_data(P1[:,0], P1[:,1])   
    return puntos

def rotacionPivote(h, k, ang):
    T1 = traslacion(-h, -k, 0)
    R = rotacion(ang)
    T2 = traslacion(h, k, 0)
    return np.matmul(np.matmul(T1, R), T2) 

def escala(sx, sy, sz):
    return np.array([[sx,  0,  0, 0], 
                     [ 0, sy,  0, 0], 
                     [ 0,  0, sz, 0], 
                     [ 0,  0,  0, 1]]).T

def rotacionPivoteX(h, k, s, ang):
    T1 = traslacion(-h, -k, s)
    R = rotacionX(ang)
    T2 = traslacion(h, k, 0)
    return np.matmul(np.matmul(T1, R), T2) 

def escalaFijo(h, k, s):
    T1 = traslacion(-h, -k, 0)
    S = escala(s,s,s)
    T2 = traslacion(h, k, 0)
    return np.matmul(np.matmul(T1, S), T2) 


def rotacion_libre(x1, y1, z1, x2, y2, z2, ang):
    p1 = np.array([x1, y1, z1])
    p2 = np.array([x2, y2, z2])

    V = (p2-p1)
    u = V / np.linalg.norm(V)
    a, b, c = u[0], u[1], u[2]
    d = (a**2 + b**2)**0.5
    Rx = np.array([[1,   0,    0, 0],
                   [0, c/d, -b/d, 0],
                   [0, b/d,  c/d, 0],
                   [0,   0,    0, 1]])
    Ry = np.array([[d, 0,-a, 0],
                   [0, 1, 0, 0],
                   [a, 0, d, 0],
                   [0, 0, 0, 1]])
    Rz = rotacion(ang)
    T1 = traslacion(-x1, -y1, -z1)
    T  = traslacion(x1, y1, z1)
    return np.matmul(np.matmul(np.matmul(np.matmul(np.matmul(np.matmul(T1,Rx.T),Ry.T),Rz),Ry),Rx),T)


def camara(Po, Pref=np.array([0,0,0]), V=np.array([0, 1, 0])):
    T = traslacion(-Po[0], -Po[1], -Po[2])
    N = Po-Pref
    n = N / np.linalg.norm(N)
    v = V / np.linalg.norm(V)
    U = np.cross(v, n)
    u = U / np.linalg.norm(U)
    v = np.cross(n, u)
    R = np.array([[u[0], u[1], u[2], 0], 
                  [v[0], v[1], v[2], 0], 
                  [n[0], n[1], n[2], 0], 
                  [  0,    0,   0,   1]]).T
    return np.matmul(T, R)

# matriz de perpectiva
def perspectiva(ang, aspect, near, far):
    cot = 1 / np.tan(ang*np.pi/360)
    sc  = (near+far)/(near-far)
    tr  = -2*near*far/(far-near)
    return np.array([[cot/aspect, 0,     0,   0],
                     [    0,     cot,    0,   0],
                     [    0,      0,    sc,  tr],
                     [    0,      0,    -1,   0]]).T

def adjust_persp(V):
    V[:,0] = -V[:,0]/V[:,2] 
    V[:,1] = -V[:,1]/V[:,2] 
    return V


def sphere(lats, lons):
    vert=[]
    ndx=[]
    dt = 2*np.pi/lons
    dp = np.pi/lats
    for i in range(lats+1):
        for j in range(lons):
            vert.append([np.cos(j*dt)*np.sin(i*dp),
                         np.cos(i*dp), 
                         np.sin(j*dt)*np.sin(i*dp), 
                         1])
    for i in range(lats):
        for j in range(lons): 
            ndx.append([i*lons+j, (i+1)*lons+(j+1)%lons, (i+1)*lons+j])
            ndx.append([i*lons+j, (i+0)*lons+(j+1)%lons, (i+1)*lons+(j+1)%lons])
    return np.array(vert), np.array(ndx, dtype='int32')

def cube():
    vert = np.array([[-1,-1,-1,1],[1,-1,-1,1],[1,1,-1,1],[-1,1,-1,1],[-1,-1,1,1],[1,-1,1,1],[1,1,1,1],[-1,1,1,1]])
    ndx  = np.array([[0,1,2],[0,2,3],[0,1,5],[0,5,4],[1,2,6],[1,6,5],[2,3,7],[2,7,6],[3,0,4],[3,4,7],[4,5,6],[4,6,7]])
    return vert, ndx

def draw_triang(ax, V, I, kolor='firebrick'):
    for i in range(I.shape[0]):
        if(V[I[i,0],2]>=0 and V[I[i,1],2]>=0 and V[I[i,2],2]>=0):
            x0 = V[I[i,0],0]
            y0 = V[I[i,0],1]
            x1 = V[I[i,1],0]
            y1 = V[I[i,1],1]
            x2 = V[I[i,2],0]
            y2 = V[I[i,2],1]
            ax.plot([x0, x1, x2, x0], [y0, y1, y2, y0], lw=0.5, color=kolor)


# Trabajo Cámara en perspectiva
#     El objetivo del trabajo es utilizar el material que se ha compartido en los cuadernos de
#     computación gráfica: Primitivas gráficas y transformaciones geométricas, para construir una
#     escena y generar una animación.


# 1. Construir una escena: plano y elementos sobre el plano
#     La escena consta de un plano de 20 segmentos, y las líneas de una serie de primitivas
#     gráficas de diferente color (como cubo, pirámide, cono, cilindro, esfera, toroide, etc) el
#     diseño de la escena es libre y los elementos se pueden repetir. El objetivo es recorrer los
#     diferentes elementos de la escena


# 2. Construir una cámara en perspectiva y generar un recorrido de la cámara en primera persona
#     El programador debe diseñar un recorrido suave de la cámara en primera persona que se
#     mueva sobre el plano y pase al lado de los objetos. Todo el tiempo se debe controlar la
#     posición y hacia donde está mirando la cámara. Si un triángulo del objeto queda detrás de la
#     cámara no se debe pintar.

# 3. Producir una animación.
#     La animación se mueve todo el tiempo, no debe quedar la escena en blanco en ningún
#     momento y debe tener al menos 200 cuadros.

def trabajo_camara():

    # Elementos
    V, I = sphere(20, 10)
    # Cubo
    V1, I1 = cube()

    # colocar elementos separados por 3 unidades y graficar
    # cubo
    V1[:,0] = V1[:,0]+3 
    V1[:,1] = V1[:,1] 
    V1[:,2] = V1[:,2]
    FIGURA = np.concatenate((V, V1))
    INDICES = np.concatenate((I, I1+V.shape[0]))
    

    def rotate_figure(c, P, P1, ax1):
        # Cámara perspectiva horizontal
        mv = camara(np.array([-5+c/6, 0.2, 0.2]), np.array([100, 0.2, 0.2]), np.array([0,-1,0]))
        # mp = perspectiva(30, 1.5, 0.1, 10)
        mp = perspectiva(60, 1.5, 0.2, 10)
        mc = np.matmul(mv, mp) 
        P2 = np.matmul(P, mc)
        P3 = adjust_persp(P2)   
        P4 = np.matmul(P1, mc)
        P5 = adjust_persp(P4)   
        ax.clear()
        ax.set_xlim((-1.5, 1.5))
        ax.set_ylim((-1.5, 1.5))
        # Graficar esfera
        draw_triang(ax, P3, I)
        # Graficar cubo
        draw_triang(ax, P5, I1)
        return ax1

    # crear animación
    fig, ax = plt.subplots()
    # plt.close()
    graf, = ax.plot(FIGURA[:,0], FIGURA[:,1])
    anim = animation.FuncAnimation(fig, rotate_figure, 60, fargs=(V, V1, graf), interval=100, blit=False)


    rc('animation', html='jshtml')
    anim
    plt.show()
    

trabajo_camara()
