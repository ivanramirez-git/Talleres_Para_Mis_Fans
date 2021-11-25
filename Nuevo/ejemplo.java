#include <iostream>



using namespace std;



class carro{
	
protected:
	
	string marca;
	
	string color;
	
	int modelo;
	
	double valor;
	
public:
	
	carro(){
		
		this->marca="";
		
		this->color="";
		
		this->modelo=0;
		
		this->valor=0;		
		
	}
	
	carro(string marca,string color,int modelo, double valor){
		
		this->marca=marca;
		
		this->color=color;
		
		this->modelo=modelo;
		
		this->valor=valor;		
		
	}
		
		void setMarca(string marca){
			
			this->marca=marca;		
			
		}
			
			
			
			void setColor(string color){
				
				this->color=color;		
				
			}
				
				void setModelo(int modelo){
					
					this->modelo=modelo;		
					
				}
					
					void setValor(double valor){
						
						this->valor=valor;
						
					}		
						
						string getMarca(){
							
							return marca;		
							
						}	
							
							string getColor(){
								
								return color;		
								
							}	
								
								int getModelo(){
									
									return modelo;		
									
								}
									
									double getValor(){
										
										return valor;		
										
									}
										
										void arrancar(){
											
											cout<<"ARRANCÓ..."<<endl;		
											
										}
											
											
											
};



class camioneta :  public carro{
	
private:
	
	double carga;
	
public:
	
	camioneta():carro(){
		
		this->carga=0;
		
	}
	
	camioneta(string marca, string color, int modelo, double valor, double carga)
		
		:carro(marca,color,modelo,valor){
		
		this->carga=carga;		
		
	}
	
	void setCarga(double carga){
		
		this->carga=carga;		
		
	}
		
		double getCarga(){
			
			return carga;
			
		}
			
};





int main(){
	
	/*carro MiCarro=carro("ferrari","rojo",2021,1000000);
	
	MiCarro.setMarca("BMW");
	
	cout<<"LA NUEVA MARCA DE MI CARRO ES: "<< MiCarro.getMarca()<<endl;
	
	MiCarro.setValor(800000);
	
	cout<<"EL NUEVO VALOR DE MI CARRO ES: "<<MiCarro.getValor()<<endl;*/
	
	camioneta MiCamioneta;
	
	MiCamioneta=camioneta("Raptor","Negro",2020,300000,2.5);
	
	cout<<"LA MARCA DE MI CAMIONETA ES: "<<MiCamioneta.getMarca()<<endl;
	
}