
Proceso Empresa
    EstructuraEmpresa <- ""
	
    // Bienvenida
    Escribir "Bienvenido al programa de Empresa"
	
    textoAuxiliar<-""
    numeroAuxiliar <- 0
	
    N<-0
    M<-0
    P<-0
	
    Escribir "Ingrese el nombre de la empresa: "
    Leer textoAuxiliar
    EstructuraEmpresa<-EstructuraEmpresa+"{°nombre°:°"+textoAuxiliar+"°,°sedes°:[{"
	
    Escribir "Ingrese el numero de sedes: "
    Leer N
	
    i<-1
    Mientras i<=N hacer
        Si i>1 Entonces
            EstructuraEmpresa<-EstructuraEmpresa+",{"
        FinSi
        Escribir "Ingrese el nomnbre de la sede: "
        Leer textoAuxiliar
        EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°secciones°:[{"
		
        Escribir "Ingrese el numero de secciones de la sede " textoAuxiliar ": "
        Leer M
		
        j<-1
        Mientras j<=M Hacer
            Si j>1 Entonces
                EstructuraEmpresa<-EstructuraEmpresa+",{"
            FinSi
            Escribir "Ingrese el nombre de la seccion: "
            Leer textoAuxiliar
            EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°empleados°:[{"
			
            Escribir "Ingrese el numero de empleados de la seccion " textoAuxiliar ": "
            Leer P
			
            k<-1
            Mientras k<=P Hacer
                Si k>1
                    EstructuraEmpresa<-EstructuraEmpresa+",{"
                FinSi
                Escribir "Ingrese el nombre del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+"°nombre°:°"+textoAuxiliar+"°,°sexo°:°"
				
                Escribir "Ingrese el sexo del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°edad°:°"
				
                Escribir "Ingrese la edad del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°salarioBasico°:°"
				
                Escribir "Ingrese el salario basico del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°,°deducciones°:°"
				
                Escribir "Ingrese el valor de deducciones del empleado: "
                Leer textoAuxiliar
                EstructuraEmpresa<-EstructuraEmpresa+textoAuxiliar+"°}"
				
                k<-k+1
            FinMientras
            P<-0
			
            EstructuraEmpresa<-EstructuraEmpresa+"]}"
			
            j<-j+1
        FinMientras
        M<-0
		
        EstructuraEmpresa<-EstructuraEmpresa+"]}"
        
        i<-i+1
    FinMientras
    N<-0
	
    EstructuraEmpresa<-EstructuraEmpresa+"]}"
	
    Escribir "Estructura de datos: "
	
    Escribir EstructuraEmpresa

FinProceso

SubProceso 
	Repetir
		secuencia_de_acciones
	Hasta Que expresion_logica
FinSubProceso
