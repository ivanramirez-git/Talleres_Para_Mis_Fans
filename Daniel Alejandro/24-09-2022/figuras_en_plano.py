import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation, rc

# # Piramide
# V = [[-1, -1, -1, 1], [-1, -1, 1, 1], [1, -1, 1, 1], [1, -1, -1, 1], [-1, -1, -1, 1], 
#      [0, 1, 0, 1], [1, -1, 1, 1], [-1, -1, 1, 1], [0, 1, 0, 1], [1, -1, -1, 1]]
# V = np.array(V)



# # Rotacion Vertical
# def prueba1():
#     # animación

#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-2, 2))
#     ax.set_ylim((-2, 2))
#     points, = ax.plot(V[:,0], V[:,1])

#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figureX, 120, fargs=(V, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba1()

# # Rotacion Horizontal
# def prueba2():
#     # animación
#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-2, 2))
#     ax.set_ylim((-2, 2))
#     points, = ax.plot(V[:,0], V[:,1])


#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figureY, 120, fargs=(V, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba2()

# def prueba3():
#     # Construir esfera 3D
#     u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
#     x = np.cos(u)*np.sin(v)
#     y = np.sin(u)*np.sin(v)
#     z = np.cos(v)

#     # Graficar esfera 3D
#     fig = plt.figure()
#     ax = fig.add_subplot(111, projection='3d')
#     ax.plot_wireframe(x, y, z, color="r")

#     # Función de animación
#     def animate(i):
#         ax.clear()
#         ax.plot_wireframe(x, y, z, color="r")
#         ax.view_init(elev=10., azim=i)

#     # Animación
#     anim = animation.FuncAnimation(fig, animate, frames=360, interval=20, blit=False)
#     plt.show()
#     plt.close()

# # prueba3()


# def prueba4():
#     P = np.array([[-1, -0.5, 0, 1], 
#               [ 0, -0.5, 0, 1], 
#               [ 0,   -1, 0, 1], 
#               [ 1,    0, 0, 1],  
#               [ 0,    1, 0, 1], 
#               [ 0,  0.5, 0, 1], 
#               [-1,  0.5, 0, 1], 
#               [-1, -0.5, 0, 1]])
#     h = -1 
#     k = 0.5
#     ang = np.pi/6
#     T1 = traslacion(-h, -k, 0)
#     plt.plot(P[:,0], P[:,1], color='lightblue')
#     P1 = np.matmul(P, T1)
#     plt.plot(P1[:,0], P1[:,1], color='y')
#     R1 = rotacion(ang)
#     P2 = np.matmul(P1, R1)
#     plt.plot(P2[:,0], P2[:,1], color='lightgreen')
#     T2 = traslacion(h, k, 0)
#     P3 = np.matmul(P2, T2)
#     plt.plot(P3[:,0], P3[:,1], color='blue')
#     plt.show()

# # prueba4()

# def prueba5():
#     P = np.array([[-1, -0.5, 0, 1], 
#               [ 0, -0.5, 0, 1], 
#               [ 0,   -1, 0, 1], 
#               [ 1,    0, 0, 1],  
#               [ 0,    1, 0, 1], 
#               [ 0,  0.5, 0, 1], 
#               [-1,  0.5, 0, 1], 
#               [-1, -0.5, 0, 1]])
#     # First set up the figure, the axes, and the plot element
#     fig, ax = plt.subplots()
#     ax.set_xlim((-5.5, 5.5))
#     ax.set_ylim((-5.5, 5.5))
#     points, = ax.plot(P[:,0], P[:,1])

#     def rotate_figure(c, mp, puntos):
#         R = rotacionPivote(2, 2, np.pi*c/60)
#         P1 = np.matmul(mp, R)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         ax.set_title('Angulo rotación:'+str(c*3))
#         #ax.axis('equal')
#         return puntos

#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(P, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()
    
# # prueba5()

# def prueba6():
#     Q = np.random.rand(400, 4)*2-1
#     Q[:,2] = Q[:,0]**2 - Q[:,1]**2  # Z = X² - Y²
#     Q[:,3] = 1 # h = 1
#     Q[0:10, :]

#     fig, ax = plt.subplots()
#     ax.set_xlim((-1.5, 1.5))
#     ax.set_ylim((-1.5, 1.5))

#     points, = ax.plot(Q[:,0], Q[:,1],'.')

#     def rotate_figure(c, mp, puntos):
#         R = rotacionPivote(0.7, 0.5, np.pi*c/60)
#         P1 = np.matmul(mp, R)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         return puntos

#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(Q, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba6()

# def prueba7():
#     Q = np.random.rand(400, 4)*2-1
#     Q[:,2] = Q[:,0]**2 - Q[:,1]**2  # Z = X² - Y²
#     Q[:,3] = 1 # h = 1
#     Q[0:10, :]

#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-1.5, 1.5))
#     ax.set_ylim((-1.5, 3.5))

#     points, = ax.plot(Q[:,0], Q[:,1],'.')

#     def rotate_figure(c, mp, puntos):
#         R = rotacionPivoteX(1, 1, 0, np.pi*c/60)
#         P1 = np.matmul(mp, R)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         return puntos

#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(Q, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba7()

# def prueba8():
#     P = np.array([[-1, -0.5, 0, 1], 
#               [ 0, -0.5, 0, 1], 
#               [ 0,   -1, 0, 1], 
#               [ 1,    0, 0, 1],  
#               [ 0,    1, 0, 1], 
#               [ 0,  0.5, 0, 1], 
#               [-1,  0.5, 0, 1], 
#               [-1, -0.5, 0, 1]])
#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-2, 15))
#     ax.set_ylim((-2, 15))
#     points, = ax.plot(P[:,0], P[:,1])

#     def rotate_figure(c, mp, puntos):
#         S = escalaFijo(0, 1, 1.02**c)
#         P1 = np.matmul(mp, S)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         return puntos

#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(P, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba8()

# # Ejercicio:
# # Hallar e implementar una matriz de transformación que permita reflejar un objeto 2D al otro lado de una línea imaginaria dado por dos puntos. Utilice la composición de las transformaciones básicas.
# def prueba9():
#     P = np.array([[-1, -0.5, 0, 1], 
#               [ 0, -0.5, 0, 1], 
#               [ 0,   -1, 0, 1], 
#               [ 1,    0, 0, 1],  
#               [ 0,    1, 0, 1], 
#               [ 0,  0.5, 0, 1], 
#               [-1,  0.5, 0, 1], 
#               [-1, -0.5, 0, 1]])
#     recta = np.array([[-2, 3, 0, 1], [4, 1, 0, 1]])
#     plt.plot(recta[:,0], recta[:,1], 'o-') # línea del punto 1 al punto 2
#     plt.plot([-4, 8], [0, 0], 'k') # eje x
#     plt.plot([0, 0], [-4, 5], 'k') # eje x
#     plt.plot(P[:,0], P[:,1])

#     T1 = traslacion(-recta[0,0], -recta[0,1], 0)
#     r2 = np.matmul(recta, T1)
#     ang = np.arctan((recta[0,1]-recta[1,1])/(recta[0,0]-recta[1,0]))

#     R1 = rotacion(-ang)
#     M  = np.matmul(T1, R1)
#     P1 = np.matmul(P, M)
#     r3 = np.matmul(r2, R1)
#     plt.plot(P1[:,0], P1[:,1])
#     plt.plot(r2[:,0], r2[:, 1], 'o-') # línea del punto 1 al punto 2
#     plt.plot(r3[:,0], r3[:, 1], 'o-') # línea del punto 1 al punto 2
#     plt.axis('equal')
#     recta[0,1]-recta[1,1], recta[0,0]-recta[1,0]
#     plt.show()

# # prueba9()


# V = np.array([[-1, -1, -5, 1], [-1, -1, 5, 1], [-1, -1, -1, 1], [-1, -1, 1, 1], [1, -1, 1, 1], [1, -1, -1, 1], [-1, -1, -1, 1], 
#      [0, 1, 0, 1], [1, -1, 1, 1], [-1, -1, 1, 1], [0, 1, 0, 1], [1, -1, -1, 1], [1, -1, 5, 1], [1, -1, -5, 1]])
# R = rotacion_libre(1.5,-1,1, 0.5,1,1, 30)


# def prueba10():
#     # animación de rotación libre
#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-2, 3))
#     ax.set_ylim((-2, 3))
#     points, = ax.plot(V[:,0], V[:,1])

#     def rotate_figure(c, mp, puntos):
#         R = rotacion_libre(2,-2,0, 1, 1,0, np.pi*c/60)
#         P1 = np.matmul(mp, R)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         return puntos
#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(V, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba10()

# def prueba11():
#     K = camara(np.array([3,1,2]), np.array([0,0,0]))
#     K

#     pos = np.array([10,5,0])
#     dir = np.array([-1,-1,-1])
#     vert = np.array([-1,2,1])
#     K = camara(pos, dir, vert)
#     print(K)
#     V1 = np.matmul(V, K)
#     plt.plot(V1[:,0], V1[:,1])
#     plt.axis('equal')
#     plt.show()

# # prueba11()

# def prueba12():
#     # Animación de la cámara

#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-1.5, 1.5))
#     ax.set_ylim((-2.5, 1.2))
#     points, = ax.plot(V[:,0], V[:,1])

#     def rotate_figure(c, mp, puntos):
#         R = camara(np.array([(-6+c/10)*2, 10, 0.1]), np.array([0,0,0]))
#         #R = camara(np.array([np.cos(c*np.pi/60), (-6+c/10)/2, np.sin(c*np.pi/60)]), np.array([0,1,0]))
#         P1 = np.matmul(mp, R)
#         puntos.set_data(P1[:,0], P1[:,1])   
#         return puntos
#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 120, fargs=(V, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba12()

# def prueba13():
#     mv = camara(np.array([2,3,2]), np.array([0,0,0]), np.array([0,-1,0]))
#     mp = perspectiva(60, 1.5, 0.1, 10)
#     mc = np.matmul(mv, mp) 
#     V1 = np.matmul(V, mc)
#     V2 = adjust_persp(V1)
#     plt.plot(V2[:,0], V2[:,1])
#     #plt.axis([-5, 5, -3, 3])
#     # plt.axis('equal')
#     plt.show()

# # prueba13()

# def prueba14():
#     # Animación de perspectiva

#     fig, ax = plt.subplots()
#     # plt.close()
#     ax.set_xlim((-6.5, 6.5))
#     ax.set_ylim((-9.0, 2.5))
#     points, = ax.plot(V[:,0], V[:,1])

#     def rotate_figure(c, P, puntos):
#         mv = camara(np.array([-5+c/6, 0.5, 2]), np.array([100,0,2]), np.array([0,-1,0]))
#         mp = perspectiva(30, 1.5, 0.1, 10)
#         mc = np.matmul(mv, mp) 
#         P1 = np.matmul(P, mc)
#         P2 = adjust_persp(P1)   
#         puntos.set_data(P2[:,0], P2[:,1])   
#         return puntos
#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 60, fargs=(V, points), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba14()

# def prueba15():
#     V, I = sphere(16,24)
#     plt.triplot(V[:,0], V[:,1], I, lw=0.5)
#     tt = plt.axis('equal')
#     plt.show()

# # prueba15()

# def prueba16():
#     V, I = sphere(16,24)
#     # plt.triplot(V[:,0], V[:,1], I, lw=0.5)
#     # tt = plt.axis('equal')

#     fig, ax = plt.subplots()
#     ax.axis('equal')
#     draw_triang(ax, V, I, 'salmon')
#     plt.show()

# # prueba16()

# def prueba17():
#     V, I = sphere(16,24)
#     V1, I1 = sphere(12,16)
#     Sc = escala(1.5, 1.5, 1.5)
#     V1 = np.matmul(V1, Sc)
#     fig, ax = plt.subplots()
#     ax.axis('equal')
#     draw_triang(ax, V, I, 'salmon')
#     draw_triang(ax, V1, I1, 'indigo')
#     plt.show()

# # prueba17()

# def prueba18():
#     V, I = sphere(16,24)
#     fig, ax = plt.subplots()
#     # plt.close()
#     graf, = ax.plot(V[:,0], V[:,1])

#     def rotate_figure(c, P, ax1):
#         mv = camara(np.array([-5+c/6, 0.2, 0.2]), np.array([100, 0.2, 0.2]), np.array([0,-1,0]))
#         mp = perspectiva(30, 1.5, 0.1, 10)
#         mc = np.matmul(mv, mp) 
#         P1 = np.matmul(P, mc)
#         P2 = adjust_persp(P1)   
#         ax.clear()
#         ax.set_xlim((-1.5, 1.5))
#         ax.set_ylim((-1.5, 1.5))
#         draw_triang(ax, P2, I)
#         draw_triang(ax, P2, I)
#         return ax1
#     # animation function: this is called sequentially
#     anim = animation.FuncAnimation(fig, rotate_figure, 60, fargs=(V, graf), interval=100, blit=False)

#     rc('animation', html='jshtml')
#     anim
#     plt.show()

# # prueba18()

# def prueba19():
    
#     #pal = np.array([x/12+0.01 for x in range(12)])

#     V, I = cube()
#     R1 = rotacionX(np.pi/6)
#     R2 = rotacionY(np.pi/4)
#     V1 = np.matmul(V, np.matmul(R1, R2))

#     #plt.tripcolor(V1[:,0], V1[:,1], I, facecolors=pal, edgecolor='k', alpha=0.4)
#     plt.triplot(V1[:,0], V1[:,1], I)
#     plt.show()

# # prueba19()

# def prueba20():

#     V, I = cube()
#     R1 = rotacionX(np.pi/6)
#     R2 = rotacionY(np.pi/4)
#     V1 = np.matmul(V, np.matmul(R1, R2))
#     # filtrar los índices donde z es mayor a cero
#     nI = np.min(V1[I][:,:,2], axis=1) > -0.3
#     plt.triplot(V1[:,0], V1[:,1], I, color='lightgray')
#     plt.triplot(V1[:,0], V1[:,1], I[nI])
#     plt.show()

# # prueba20()


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


# Modificar primitivas gráficas
#   Generar una matriz de vértices y de índices
#   Dibujar triángulos a un plot
#   Filtrar los triángulos que se pintan
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

def torus(r, R, lats, lons):
    vert=[]
    ndx=[]
    dt = 2*np.pi/lons
    dp = 2*np.pi/lats
    for i in range(lats+1):
        for j in range(lons):
            vert.append([(R+r*np.cos(j*dt))*np.cos(i*dp),
                         (R+r*np.cos(j*dt))*np.sin(i*dp), 
                         r*np.sin(j*dt), 
                         1])
    for i in range(lats):
        for j in range(lons): 
            ndx.append([i*lons+j, (i+1)*lons+(j+1)%lons, (i+1)*lons+j])
            ndx.append([i*lons+j, (i+0)*lons+(j+1)%lons, (i+1)*lons+(j+1)%lons])
    return np.array(vert), np.array(ndx, dtype='int32')


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
    # Ejemplos
    
    # def prueba18():
    #     V, I = sphere(16,24)
    #     fig, ax = plt.subplots()
    #     # plt.close()
    #     graf, = ax.plot(V[:,0], V[:,1])

    #     def rotate_figure(c, P, ax1):
    #         mv = camara(np.array([-5+c/6, 0.2, 0.2]), np.array([100, 0.2, 0.2]), np.array([0,-1,0]))
    #         mp = perspectiva(30, 1.5, 0.1, 10)
    #         mc = np.matmul(mv, mp) 
    #         P1 = np.matmul(P, mc)
    #         P2 = adjust_persp(P1)   
    #         ax.clear()
    #         ax.set_xlim((-1.5, 1.5))
    #         ax.set_ylim((-1.5, 1.5))
    #         draw_triang(ax, P2, I)
    #         draw_triang(ax, P2, I)
    #         return ax1
    #     # animation function: this is called sequentially
    #     anim = animation.FuncAnimation(fig, rotate_figure, 60, fargs=(V, graf), interval=100, blit=False)

    #     rc('animation', html='jshtml')
    #     anim
    #     plt.show()

    # # prueba18()
    # def prueba20():

    #     V, I = cube()
    #     R1 = rotacionX(np.pi/6)
    #     R2 = rotacionY(np.pi/4)
    #     V1 = np.matmul(V, np.matmul(R1, R2))
    #     # filtrar los índices donde z es mayor a cero
    #     nI = np.min(V1[I][:,:,2], axis=1) > -0.3
    #     plt.triplot(V1[:,0], V1[:,1], I, color='lightgray')
    #     plt.triplot(V1[:,0], V1[:,1], I[nI])
    #     plt.show()

    # # prueba20()

    
    # # Construir esfera 3D
    # u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
    # x = np.cos(u)*np.sin(v)
    # y = np.sin(u)*np.sin(v)
    # z = np.cos(v)

    # # Graficar esfera 3D
    # fig = plt.figure()
    # ax = fig.add_subplot(111, projection='3d')
    # ax.plot_wireframe(x, y, z, color="r")

    # # Función de animación
    # def animate(i):
    #     ax.clear()
    #     ax.plot_wireframe(x, y, z, color="r")
    #     ax.view_init(elev=10., azim=i)

    # # Animación
    # anim = animation.FuncAnimation(fig, animate, frames=360, interval=20, blit=False)
    # plt.show()
    # plt.close()

    # Elementos
    # Esfera
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
        # Graficar torus
        # draw_triang(ax, P5, I2)
        return ax1

    # # Graficar figuras en 3D, proporción 1:1:1
    # fig = plt.figure()
    # ax = fig.add_subplot(111, projection='3d')
    # ax.plot_trisurf(V[:,0], V[:,1], V[:,2], triangles=I, color='lightgray')
    # ax.plot_trisurf(V1[:,0], V1[:,1], V1[:,2], triangles=I1, color='lightgray')
    # ax.set_aspect('equal')
    # ax.set_xlim((-10, 10))
    # ax.set_ylim((-10, 10))
    # ax.set_zlim((0, 10))
    # plt.show()

    # crear animación
    fig, ax = plt.subplots()
    # plt.close()
    graf, = ax.plot(FIGURA[:,0], FIGURA[:,1])
    anim = animation.FuncAnimation(fig, rotate_figure, 60, fargs=(V, V1, graf), interval=100, blit=False)


    rc('animation', html='jshtml')
    anim
    plt.show()
    

trabajo_camara()

# def prueba16():
#     V, I = sphere(5,10)
#     # plt.triplot(V[:,0], V[:,1], I, lw=0.5)
#     # tt = plt.axis('equal')

#     fig, ax = plt.subplots()
#     ax.axis('equal')
#     draw_triang(ax, V, I, 'salmon')
#     plt.show()

# prueba16()
