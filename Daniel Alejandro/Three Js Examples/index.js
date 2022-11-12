//creating scene
let scene = new THREE.Scene(); // La escena es el contenedor de todos los objetos que se van a mostrar en la pantalla
scene.background = new THREE.Color(0x2a3b4c); // Color de fondo de la escena
scene.fog = new THREE.Fog(0x2a3b4c, 0.1, 8); // Creamos un efecto de niebla

//add camera
let camera = new THREE.PerspectiveCamera(
    75, // Campo de visión
    window.innerWidth / window.innerHeight // Relación de aspecto, es decir, el ancho de la pantalla dividido entre el alto
);

//renderer
let renderer = new THREE.WebGLRenderer(); // El renderer es el encargado de mostrar la escena en la pantalla
renderer.setSize(window.innerWidth - 15, window.innerHeight - 15); // Tamaño de la pantalla
document.body.appendChild(renderer.domElement); // Agregamos el renderer al body del documento

//add geometry
let geometry = new THREE.BoxGeometry(); // Creamos una geometría de un cubo
// material
let material = new THREE.MeshBasicMaterial({ color: 0x00ff00 }); // Creamos un material para el cubo, en este caso es un material básico con color verde y con el wireframe activado

let cube = new THREE.Mesh(geometry, material); // Creamos el cubo con la geometría y el material

scene.add(cube); // Agregamos el cubo a la escena

camera.position.z = 5; // Posicionamos la cámara a 5 unidades de profundidad


//animation
let animate = function () { // Función que se va a ejecutar en cada frame
    requestAnimationFrame(animate); // Llamamos a la función animate en cada frame

    // cube.rotation.x += 0.01; // Rotamos el cubo en el eje x
    // cube.rotation.y += 0.01; // Rotamos el cubo en el eje y

    renderer.render(scene, camera); // Renderizamos la escena

}

// listener of keydown
document.addEventListener('keydown', function (event) {
    if (event.key == 'ArrowUp') {
        camera.position.z -= 0.1;
    }
    if (event.key == 'ArrowDown') {
        camera.position.z += 0.1;
    }
});

// listener of mouse move for cube with mouse click
document.addEventListener('mousemove', function (event) {
    if (event.buttons == 1) {
        cube.rotation.x = event.clientY / 100;
        cube.rotation.y = - event.clientX / 100;
    }
});


animate(); // Llamamos a la función animate

