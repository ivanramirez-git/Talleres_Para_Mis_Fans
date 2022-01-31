#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// un pais puede ser almacenado como un pair <string, float>, donde el string es el nombre del pais y el int es el numero de habitantes
class paises:private list<pair<string,float> >
{
    private:
        int n_paises;
    public:
        // constructor
        paises(int n_paises):n_paises(n_paises)
        {
            for(int i=0;i<n_paises;i++)
            {
                string nombre;
                float habitantes;
                cin>>nombre>>habitantes;
                this->push_back(make_pair(nombre,habitantes));
            }
        }
        paises():n_paises(0)
        {
        }
        // sobrecargar >>, <<
        friend istream& operator>>(istream& is, paises& p)
        {
            string nombre;
            float habitantes;
            while(is>>nombre>>habitantes)
            {
                p.push_back(make_pair(nombre,habitantes));
                p.n_paises++;
            }
            return is;
        }
        friend ostream& operator<<(ostream& os, const paises& p)
        {
            for(auto i:p)
            {
                os<<i.first<<" "<<i.second<<endl;
            }
            return os;
        }
        // rango de habitantes, Rango: min, max
        string rango()
        {
            if(n_paises==0)
            {
                return "No hay paises";
            }
            else
            {
                float min=this->front().second;
                float max=this->front().second;
                for(int i=1;i<n_paises;i++)
                {
                    if(this->front().second<min)
                    {
                        min=this->front().second;
                    }
                    if(this->front().second>max)
                    {
                        max=this->front().second;
                    }
                    this->pop_front();
                }
                return "Rango: ("+to_string(min)+","+to_string(max)+")";
            }
        }
        // agrupar paises en k grupos, guardar la informacion en una estructura: vector < queue < pair <string,float> > >
        vector<queue<pair<string,float> > > agrupar(int k)
        {
            if(n_paises==0)
            {
                cout<<"No hay paises"<<endl;
                return vector<queue<pair<string,float> > >();
            }
            else
            {
                vector<queue<pair<string,float> > > v(k);
                for(int i=0;i<n_paises;i++)
                {
                    v[i%k].push(this->front());
                    this->pop_front();
                }
                return v;
            }
        }
};

// Pruebas
void prueba1()
{
    // leer archivo paises_2.txt
    ifstream archivo("paises_2.txt");
    paises p(0);
    archivo>>p;
    cout<<"Paises leidos: "<<endl;
    cout<<p<<endl;
    // ordenar por habitantes
    //p.ordenar_habitantes();
    cout<<"Ordenado por habitantes: "<<endl;
    cout<<p<<endl;
    // rango de habitantes
    cout<<"Rango de habitantes: "<<endl;
    cout<<p.rango()<<endl;
    // agrupar paises en k grupos
    cout<<"Ingrese k: ";
    int k;
    cin>>k;
    vector<queue<pair<string,float> > > v=p.agrupar(k);
    cout<<"Agrupados en "<<k<<" grupos: "<<endl;
    for(int i=0;i<k;i++)
    {
        cout<<"Grupo "<<i+1<<": "<<endl;
        while(!v[i].empty())
        {
            cout<<v[i].front().first<<" "<<v[i].front().second<<endl;
            v[i].pop();
        }
    }
}

// Programa principal
int main()
{
    prueba1();
    return 0;
}