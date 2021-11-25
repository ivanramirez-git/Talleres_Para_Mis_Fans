#include <iostream>
#include <map>
//vec
#include <vector>

using namespace std;


// Clases
/*

1. Clase Atencion:
    1. int fecha (Formato DDMMAAAA) que registra la fecha de la atención.
    2. string sintomas que registra los síntomas presentados por el paciente.
    3. string diagnos co que registra el diagnostico realizado por el medico.
2. Clase Paciente:
    1. string RUT.
    2. string Nombre.
    3. string ApellidoPaterno.
    4. string ApellidoMaterno.
    5. int fechaNacimiento (Formato DDMMAAAA).
    6. vector <Atencion *> fichaMedica donde se registran todas las atenciones que ha recibido el
    paciente dentro del hospital.
3. Clase Hospital:
    1. map <string, Paciente *> Clientes que registra todos los pacientes que se han atendido
    alguna vez en el hospital.
    2. Paciente *BOX[50] que registra los pacientes que están siendo atendidos en urgencia, NULL
    significa que el box se encuentra disponible.

*/

// Clase Atencion
class Atencion {
    private:
        int fecha;
        string sintomas;
        string diagnos;
    public:
    // Constructor
    Atencion() {
    }
    Atencion(int fecha, string sintomas) {
        this->fecha = fecha;
        this->sintomas = sintomas;
    }
    // Setters
    void setFecha(int fecha) {
        this->fecha = fecha;
    }
    void setSintomas(string sintomas) {
        this->sintomas = sintomas;
    }
    void setDiagnostico(string diagnos) {
        this->diagnos = diagnos;
    }
    // Getters
    int getFecha() {
        return fecha;
    }
    string getSintomas() {
        return sintomas;
    }
    string getDiagnostico() {
        return diagnos;
    }

};

// Class Paciente
class Paciente {
    private:
        string RUT;
        string Nombre;
        string ApellidoPaterno;
        string ApellidoMaterno;
        int fechaNacimiento;
        vector<Atencion*> fichaMedica;
    public:
    // Constructor
    Paciente() {
    }
    Paciente(string RUT, string Nombre, string ApellidoPaterno, string ApellidoMaterno, int fechaNacimiento) {
        this->RUT = RUT;
        this->Nombre = Nombre;
        this->ApellidoPaterno = ApellidoPaterno;
        this->ApellidoMaterno = ApellidoMaterno;
        this->fechaNacimiento = fechaNacimiento;
    }
    // Setters
    void setRUT(string RUT) {
        this->RUT = RUT;
    }
    void setNombre(string Nombre) {
        this->Nombre = Nombre;
    }
    void setApellidoPaterno(string ApellidoPaterno) {
        this->ApellidoPaterno = ApellidoPaterno;
    }
    void setApellidoMaterno(string ApellidoMaterno) {
        this->ApellidoMaterno = ApellidoMaterno;
    }
    void setFechaNacimiento(int fechaNacimiento) {
        this->fechaNacimiento = fechaNacimiento;
    }
    void setFichaMedica(vector<Atencion*> fichaMedica) {
        this->fichaMedica = fichaMedica;
    }
    // Getters
    string getRUT() {
        return RUT;
    }
    string getNombre() {
        return Nombre;
    }
    string getApellidoPaterno() {
        return ApellidoPaterno;
    }
    string getApellidoMaterno() {
        return ApellidoMaterno;
    }
    int getFechaNacimiento() {
        return fechaNacimiento;
    }
    vector<Atencion*> getFichaMedica() {
        return fichaMedica;
    }

    // Metodos para vector
    void agregarAtencion(Atencion* atencion) {
        fichaMedica.push_back(atencion);
    }
    void eliminarAtencion(int pos) {
        fichaMedica.erase(fichaMedica.begin() + pos);
    }
    void modificarAtencion(int pos, Atencion* atencion) {
        fichaMedica[pos] = atencion;
    }
    void modificarAtencion(Atencion* atencion) {
        // Modifica la ultima atencion
        fichaMedica[fichaMedica.size() - 1] = atencion;
    }
    void mostrarAtenciones() {
        for (int i = 0; i < fichaMedica.size(); i++) {
            cout << "Id: " << i << endl;
            cout << "Fecha: " << fichaMedica[i]->getFecha() << endl;
            cout << "Sintomas: " << fichaMedica[i]->getSintomas() << endl;
            cout << "Diagnostico: " << fichaMedica[i]->getDiagnostico() << endl;
        }
    }
    void actualizarAtencion(int pos, Atencion* atencion) {
        fichaMedica[pos] = atencion;
    }
    Atencion* getAtencion(int pos) {
        return fichaMedica[pos];
    }
    int getCantidadAtenciones() {
        return fichaMedica.size();
    }
};

// Class Hospital
class Hospital {
    private:
        map <string, Paciente *> Clientes;
        Paciente *BOX[50];

        // Vector de Clientes en espera
        vector<string> esperaRUT;
    public:
    // Constructor
    Hospital() {
    }
    // Setters
    void setClientes(map <string, Paciente *> Clientes) {
        this->Clientes = Clientes;
    }
    void setBOX(Paciente *BOX[50]) {
        // Copia el vector de BOX
        for (int i = 0; i < 50; i++) {
            this->BOX[i] = BOX[i];
        }
    }
    // Getters
    map <string, Paciente *> getClientes() {
        return Clientes;
    }
    Paciente *getBOX(int pos) {
        return BOX[pos];
    }
    // Metodos para map
    void agregarCliente(string RUT, Paciente *paciente) {
        Clientes.insert(pair<string, Paciente *>(RUT, paciente));
    }
    void eliminarCliente(string RUT) {
        Clientes.erase(RUT);
    }
    void modificarCliente(Paciente *paciente) {
        Clientes[paciente->getRUT()] = paciente;
    }
    void mostrarClientes() {
        for (map<string, Paciente *>::iterator it = Clientes.begin(); it != Clientes.end(); ++it) {
            cout << "RUT: " << it->first << endl;
            cout << "Nombre: " << it->second->getNombre() << endl;
            cout << "Apellido Paterno: " << it->second->getApellidoPaterno() << endl;
            cout << "Apellido Materno: " << it->second->getApellidoMaterno() << endl;
            cout << "Fecha de Nacimiento: " << it->second->getFechaNacimiento() << endl;
            cout << "Ficha Medica: " << endl;
            it->second->mostrarAtenciones();
        }
    }
    void actualizarCliente(string RUT, Paciente *paciente) {
        Clientes[RUT] = paciente;
    }
    bool buscarCliente(string RUT) {
        if (Clientes.find(RUT) != Clientes.end()) {
            return true;
        } else {
            return false;
        }
    }
    Paciente *retornarCliente(string RUT) {
        return Clientes[RUT];
    }
    // Metodos para vector
    int agregarPaciente(Paciente *paciente) {
        for (int i = 0; i < 50; i++) {
            if (BOX[i] == NULL) {
                BOX[i] = paciente;
                return i;
            }else if (BOX[i]->getRUT() == paciente->getRUT()) {
                return -1;
            }            
        }
        return -2;
    }
    void eliminarPaciente(int pos) {
        BOX[pos] = NULL;
    }
    void mostrarPacientes() {
        for (int i = 0; i < 50; i++) {
            if (BOX[i] != NULL) {
                cout << "Id: " << i << endl;
                cout << "RUT: " << BOX[i]->getRUT() << endl;
                cout << "Nombre: " << BOX[i]->getNombre() << endl;
                cout << "Apellido Paterno: " << BOX[i]->getApellidoPaterno() << endl;
                cout << "Apellido Materno: " << BOX[i]->getApellidoMaterno() << endl;
                cout << "Fecha de Nacimiento: " << BOX[i]->getFechaNacimiento() << endl;
                cout << "Ficha Medica: " << endl;
                BOX[i]->mostrarAtenciones();
            }
        }
    }
    void actualizarPaciente(int pos, Paciente *paciente) {
        BOX[pos] = paciente;
    }
    bool buscarPaciente(int pos) {
        if (BOX[pos] != NULL) {
            return true;
        } else {
            return false;
        }
    }
    void boxDisponibles() {
        for (int i = 0; i < 50; i++) {
            if (BOX[i] == NULL) {
                cout << "Id: " << i << endl;
            }
        }
    }
    Paciente *retornarPaciente(int pos) {
        return BOX[pos];
    }
    // Metodos para vector de espera
    void agregarEspera(string RUT) {
        esperaRUT.push_back(RUT);
    }
    string desencolarEspera() {
        string RUT = esperaRUT[0];
        esperaRUT.erase(esperaRUT.begin());
        return RUT;
    }
    bool eliminarEspera(string RUT) {
        for (int i = 0; i < esperaRUT.size(); i++) {
            if (esperaRUT[i] == RUT) {
                esperaRUT.erase(esperaRUT.begin() + i);
                return true;
            }
        }
        return false;
    }
    void mostrarEspera() {
        for (int i = 0; i < esperaRUT.size(); i++) {
            cout << i << ": " << esperaRUT[i] << endl;
        }
    }

};

// Funciones
/*
1. Encolar Paciente: en este menú se pregunta al paciente su Rut y se busca su existencia dentro
de la base de datos del hospital (mapa de clientes), en caso de no exis r deberán solicitar todos
sus datos personales. Luego se le preguntan los síntomas y la fecha actual para ingresar esa
información a la ficha medica del paciente.
*/
void encolarPaciente(Hospital *hospital){
    // Paciente
    Paciente *paciente = new Paciente();
    
    // Rut
    string RUT;
    cout << "Ingrese su RUT: ";
    cin >> RUT;

    // Buscar en mapa
    if (hospital->buscarCliente(RUT)) {
        cout << "Paciente encontrado" << endl;
        paciente = hospital->retornarCliente(RUT);
        // Imprimir datos
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Apellido Paterno: " << paciente->getApellidoPaterno() << endl;
        cout << "Apellido Materno: " << paciente->getApellidoMaterno() << endl;
        cout << "Fecha de Nacimiento: " << paciente->getFechaNacimiento() << endl;
        cout << endl;
        // Nueva atencion
        cout << "Nueva atencion" << endl;
        Atencion *atencion = new Atencion();
        // Sintomas
        string sintomas;
        cout << "Ingrese los sintomas: ";
        cin >> sintomas;
        atencion->setSintomas(sintomas);
        // Fecha
        int fecha;
        cout << "Ingrese la fecha actual (Formato DDMMAAAA): ";
        cin >> fecha;
        atencion->setFecha(fecha);
        // Agregar atencion
        paciente->agregarAtencion(atencion);
        // Atencion agregada
        cout << "Atencion agregada" << endl;
        // Agregar a lista de espera
        hospital->agregarEspera(RUT);
        // Actualizar paciente
        hospital->actualizarCliente(RUT, paciente);
    } else {
        cout << "Paciente no encontrado" << endl;
        // Nuevo paciente
        cout << "Nuevo paciente" << endl;
        // Nombre
        string nombre;
        cout << "Ingrese su nombre: ";
        cin >> nombre;
        paciente->setNombre(nombre);
        // Apellido Paterno
        string apellidoPaterno;
        cout << "Ingrese su apellido paterno: ";
        cin >> apellidoPaterno;
        paciente->setApellidoPaterno(apellidoPaterno);
        // Apellido Materno
        string apellidoMaterno;
        cout << "Ingrese su apellido materno: ";
        cin >> apellidoMaterno;
        paciente->setApellidoMaterno(apellidoMaterno);
        // Fecha de Nacimiento
        int fechaNacimiento;
        cout << "Ingrese su fecha de nacimiento (Formato DDMMAAAA): ";
        cin >> fechaNacimiento;
        paciente->setFechaNacimiento(fechaNacimiento);
        // Nueva atencion
        cout << "Nueva atencion" << endl;
        Atencion *atencion = new Atencion();
        // Sintomas
        string sintomas;
        cout << "Ingrese los sintomas: ";
        cin >> sintomas;
        atencion->setSintomas(sintomas);
        // Fecha
        int fecha;
        cout << "Ingrese la fecha actual (Formato DDMMAAAA): ";
        cin >> fecha;
        atencion->setFecha(fecha);
        // Agregar atencion
        paciente->agregarAtencion(atencion);
        // Atencion agregada
        cout << "Atencion agregada" << endl;
        // Agregar paciente
        hospital->agregarCliente(RUT, paciente);
        // Agregar a lista de espera
        hospital->agregarEspera(RUT);
        // Paciente agregado
        cout << "Paciente agregado" << endl;
        // Finalizar
        cout << endl;
    }

}

/*

2. Ingresar Paciente a Box: que ingresa al primer paciente de la lista de espera imprimiendo por
pantalla un mensaje indicando el numero de box, el nombre y ambos apellidos del paciente.

*/
void ingresarPaciente(Hospital *hospital){
    // Paciente
    Paciente *paciente = new Paciente();
    // Rut
    string RUT;
    RUT = hospital->desencolarEspera();
    paciente = hospital->retornarCliente(RUT);
    // Imprimir datos
    cout << "Nombre: " << paciente->getNombre() << endl;
    cout << "Apellido Paterno: " << paciente->getApellidoPaterno() << endl;
    cout << "Apellido Materno: " << paciente->getApellidoMaterno() << endl;
    cout << endl;
    // Box
    int box = hospital->agregarPaciente(paciente);
    if (box < 0) {
        cout << "No hay box disponible" << endl;
    } else {
        cout << "Paciente ingresado a box " << box << endl;
    }
}
/*

3. Ingresar Paciente Urgente: Donde se pregunta el Rut del paciente en situación de emergencia, y
se ingresa a un box disponible indicando por pantalla el numero de box, el nombre y los apellidos
del paciente. (El paciente debe exis r en la lista de espera y es eliminado de esa lista para ser
ingresado inmediatamente, independiente de la posición que posea en la cola)

*/
void ingresarPacienteUrgencia(Hospital *hospital){
    // Paciente
    Paciente *paciente = new Paciente();
    // Rut
    string RUT;
    cout << "Ingrese su RUT: ";
    cin >> RUT;
    // Buscar en mapa
    if (hospital->buscarCliente(RUT)) {
        cout << "Paciente encontrado" << endl;
        paciente = hospital->retornarCliente(RUT);
        // Imprimir datos
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Apellido Paterno: " << paciente->getApellidoPaterno() << endl;
        cout << "Apellido Materno: " << paciente->getApellidoMaterno() << endl;
        cout << endl;
        // Box
        int box = hospital->agregarPaciente(paciente);
        if (box < 0) {
            cout << "No hay box disponible" << endl;
        } else {
            cout << "Paciente ingresado a box " << box << endl;
            // Eliminar de lista de espera
            hospital->eliminarEspera(RUT);
        }
    } else {
        cout << "Paciente no encontrado" << endl;
    }
}

/*

4. Dar Paciente de Alta: Que recibe el numero de box y el diagnosco del paciente, el box es
desocupado y se registra el diagnosco en la ficha medica del paciente. (Ultima atención)

*/
void darPacienteAlta(Hospital *hospital){
    // Paciente
    Paciente *paciente = new Paciente();
    // Box
    int box;
    cout << "Ingrese el numero de box: ";
    cin >> box;
    // Buscar si hay paciente en box
    if (hospital->buscarPaciente(box)) {
        cout << "Paciente encontrado" << endl;
        paciente = hospital->retornarPaciente(box);
        // Mostrar datos
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Apellido Paterno: " << paciente->getApellidoPaterno() << endl;
        cout << "Apellido Materno: " << paciente->getApellidoMaterno() << endl;
        cout << endl;
        // Ultima atencion
        Atencion *atencion = new Atencion();
        atencion = paciente->getAtencion(paciente->getCantidadAtenciones() - 1);
        // Mostrar atencion
        cout << "Ultima atencion" << endl;
        cout << "Sintomas: " << atencion->getSintomas() << endl;
        cout << "Fecha: " << atencion->getFecha() << endl;
        cout << endl;
        // Diagnostico
        string diagnostico;
        cout << "Ingrese el diagnostico: ";
        cin >> diagnostico;
        // Agregar diagnostico
        atencion->setDiagnostico(diagnostico);
        cout << "Diagnostico agregado" << endl;
        // Desocupar box
        hospital->eliminarPaciente(box);
        cout << "Box << " << box << " disponible" << endl;
        // Finalizar
        cout << endl;
        // Modificar atencion
        paciente->modificarAtencion(atencion);
        // Modificar paciente
        hospital->modificarCliente(paciente);
        // Paciente dado de alta
        cout << "Paciente dado de alta" << endl;
    } else {
        cout << "Paciente no encontrado" << endl;
    }
    // Finalizar
}

/*

5. Imprimir Ficha Medica: Que recibe el numero de box y muestra toda la información personal y
medica del paciente que se encuentra siendo atendido en ese box.

*/
void imprimirFichaMedica(Hospital *hospital){
    // Paciente
    Paciente *paciente = new Paciente();
    // Box
    int box;
    cout << "Ingrese el numero de box: ";
    cin >> box;
    // Buscar si hay paciente en box
    if (hospital->buscarPaciente(box)) {
        cout << "Paciente encontrado" << endl;
        paciente = hospital->retornarPaciente(box);
        // Mostrar datos
        cout << "Nombre: " << paciente->getNombre() << endl;
        cout << "Apellido Paterno: " << paciente->getApellidoPaterno() << endl;
        cout << "Apellido Materno: " << paciente->getApellidoMaterno() << endl;
        cout << endl;
        // Mostrar atenciones
        cout << "Atenciones" << endl;
        for (int i = 0; i < paciente->getCantidadAtenciones(); i++) {
            Atencion *atencion = new Atencion();
            atencion = paciente->getAtencion(i);
            cout << "Sintomas: " << atencion->getSintomas() << endl;
            cout << "Fecha: " << atencion->getFecha() << endl;
            cout << "Diagnostico: " << atencion->getDiagnostico() << endl;
            cout << endl;
        }
        // Finalizar
        cout << endl;
    } else {
        cout << "Paciente no encontrado" << endl;
    }
    // Finalizar
}

/*

6. BOX disponibles: Que muestra por pantalla lo números de los box de atención que se
encuentran disponible.

*/
void boxDisponibles(Hospital *hospital){
    // Boxes
    cout << "Boxes disponibles" << endl;
    hospital->boxDisponibles();
    // Finalizar
}

// Main
int main() {
    Hospital *hospital = new Hospital();
    int opcion;
    do{
        cout << "1. Encolar Paciente" << endl;
        cout << "2. Ingresar Paciente a Box" << endl;
        cout << "3. Ingresar Paciente Urgente" << endl;
        cout << "4. Dar Paciente de Alta" << endl;
        cout << "5. Imprimir Ficha Medica" << endl;
        cout << "6. BOX disponibles" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            encolarPaciente(hospital);
        } else if (opcion == 2) {
            ingresarPaciente(hospital);
        } else if (opcion == 3) {
            ingresarPacienteUrgencia(hospital);
        } else if (opcion == 4) {
            darPacienteAlta(hospital);
        } else if (opcion == 5) {
            imprimirFichaMedica(hospital);
        } else if (opcion == 6) {
            boxDisponibles(hospital);
        } else if (opcion == 7) {
            break;
        } else {
            cout << "Opcion invalida" << endl;
        }
        
    }while(opcion != 7);


    return 0;
}
