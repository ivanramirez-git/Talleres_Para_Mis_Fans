

Rx = rotacionX(30*np.pi/180)
Ry = rotacionY(30*np.pi/180)
Rz = rotacionZ(30*np.pi/180)

# Construir espacio de puntos 3D
x = np.linspace(-1, 1, 10)
y = np.linspace(-1, 1, 10)
X, Y = np.meshgrid(x, y)

# Construir matriz de puntos 3D
P = np.array([X.flatten(), Y.flatten(), np.zeros(X.size), np.ones(X.size)])
print('matriz puntos P:', P.shape)
print(P)

# Rotar puntos 3D
P1 = np.matmul(Rx, P)
P2 = np.matmul(Ry, P)
P3 = np.matmul(Rz, P)

# Graficar puntos 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(P[0,:], P[1,:], P[2,:], c='b', marker='o')
ax.scatter(P1[0,:], P1[1,:], P1[2,:], c='r', marker='o')


# Graficar esfera 3D
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
x = np.cos(u)*np.sin(v)
y = np.sin(u)*np.sin(v)
z = np.cos(v)
ax.plot_wireframe(x, y, z, color="r")
plt.show()

# animación de rotación
from matplotlib import animation, rc

Rx = rotacionX(30*np.pi/180)
Ry = rotacionY(30*np.pi/180)
Rz = rotacionZ(30*np.pi/180)

# Construir esfera 3D
u, v = np.mgrid[0:2*np.pi:20j, 0:np.pi:10j]
x = np.cos(u)*np.sin(v)
y = np.sin(u)*np.sin(v)
z = np.cos(v)

# Graficar esfera 3D
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_wireframe(x, y, z, color="r")

# Función de animación
def animate(i):
    ax.clear()
    ax.plot_wireframe(x, y, z, color="r")
    ax.view_init(elev=10., azim=i)

# Animación
anim = animation.FuncAnimation(fig, animate, frames=360, interval=20, blit=False)
plt.show()
plt.close()




# Definir las primitivas
cubo = np.array([[-1,-1,-1,1],[1,-1,-1,1],[1,1,-1,1],[-1,1,-1,1],[-1,-1,1,1],[1,-1,1,1],[1,1,1,1],[-1,1,1,1]])
# Definir las transformaciones
R1 = rotacionX(np.pi/6)
R2 = rotacionY(np.pi/4)
T1 = traslacion(0, 0, 3)
T2 = traslacion(0, 0, 6)
T3 = traslacion(0, 0, 9)
T4 = traslacion(0, 0, 12)
T5 = traslacion(0, 0, 15)
T6 = traslacion(0, 0, 18)
# Aplicar las transformaciones
cubo1 = np.matmul(cubo, np.matmul(R1, R2))
cubo2 = np.matmul(cubo1, T1)
cubo3 = np.matmul(cubo2, T2)
cubo4 = np.matmul(cubo3, T3)
cubo5 = np.matmul(cubo4, T4)
cubo6 = np.matmul(cubo5, T5)
cubo7 = np.matmul(cubo6, T6)
# Definir las caras
ndx  = np.array([[0,1,2],[0,2,3],[0,1,5],[0,5,4],[1,2,6],[1,6,5],[2,3,7],[2,7,6],[3,0,4],[3,4,7],[4,5,6],[4,6,7]])
# Definir la cámara
mv = camara(np.array([-5, 0.2, 0.2]), np.array([100, 0.2, 0.2]), np.array([0, 1, 0]), 1, 1, 1, 100)
# Definir la figura
fig = plt.figure(figsize=(10,10))
ax = fig.add_subplot(111, projection='3d')
ax.set_xlim((-10, 10))
ax.set_ylim((-10, 10))
ax.set_zlim((-10, 10))
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
# Definir la animación
def init():
    ax.clear()
    ax.set_xlim((-10, 10))
    ax.set_ylim((-10, 10))
    ax.set_zlim((-10, 10))
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    return fig,
def animate(i):
    ax.clear()
    ax.set_xlim((-10, 10))
    ax.set_ylim((-10, 10))
    ax.set_zlim((-10, 10))
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    # Dibujar el plano
    ax.plot(plano[:,0], plano[:,1], plano[:,2], color='black')
    # Dibujar los cubos
    ax.plot(cubo1[:,0], cubo1[:,1], cubo1[:,2], color='red')
    ax.plot(cubo2[:,0], cubo2[:,1], cubo2[:,2], color='red')
    ax.plot(cubo3[:,0], cubo3[:,1], cubo3[:,2], color='red')
    ax.plot(cubo4[:,0], cubo4[:,1], cubo4[:,2], color='red')
    ax.plot(cubo5[:,0], cubo5[:,1], cubo5[:,2], color='red')
    ax.plot(cubo6[:,0], cubo6[:,1], cubo6[:,2], color='red')
    ax.plot(cubo7[:,0], cubo7[:,1], cubo7[:,2], color='red')
    # Dibujar las caras
    ax.plot_trisurf(cubo1[:,0], cubo1[:,1], cubo1[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo2[:,0], cubo2[:,1], cubo2[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo3[:,0], cubo3[:,1], cubo3[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo4[:,0], cubo4[:,1], cubo4[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo5[:,0], cubo5[:,1], cubo5[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo6[:,0], cubo6[:,1], cubo6[:,2], triangles=ndx, color='red', alpha=0.5)
    ax.plot_trisurf(cubo7[:,0], cubo7[:,1], cubo7[:,2], triangles=ndx, color='red', alpha=0.5)
    # Dibujar la cámara
    ax.plot(mv[:,0], mv[:,1], mv[:,2], color='blue')
    # Rotar los cubos
    cubo1 = np.matmul(cubo1, rotacionY(np.pi/180))
    cubo2 = np.matmul(cubo2, rotacionY(np.pi/180))
    cubo3 = np.matmul(cubo3, rotacionY(np.pi/180))
    cubo4 = np.matmul(cubo4, rotacionY(np.pi/180))
    cubo5 = np.matmul(cubo5, rotacionY(np.pi/180))
    cubo6 = np.matmul(cubo6, rotacionY(np.pi/180))
    cubo7 = np.matmul(cubo7, rotacionY(np.pi/180))
    return fig,
# Ejecutar la animación
anim = animation.FuncAnimation(fig, animate, init_func=init, frames=360, interval=20, blit=True)
plt.show()

