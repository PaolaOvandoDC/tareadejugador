#include <iostream>
#include <time.h>
using namespace std;
class player
	{
	private:
		short posiciontiro;
	public:
		int nrogoles;
		player()
		{
			posiciontiro = 0;
			nrogoles =0;
		}
		void patear()
		{ 
			do{
			cout<<"introduzca su direccion"<<endl;
			cin>>posiciontiro;
			}while(posiciontiro < 1 || posiciontiro >9);
		}
		short getposiciontiro()
		{
			return posiciontiro;
		}
		int getnrogoles()
		{
			return nrogoles;
		}
};
class arquero
	{
	private:
		short posicioninicial;
		short posiciontapada;
	public:
		float altura;
		int nroatajadas;
		arquero(float alt=1.75)
		{
			nroatajadas = 0;
			altura = alt;
			posicioninicial = rand()%9+1;
			posiciontapada = posicioninicial;
		}
		void atajar()
		{
			
			posiciontapada = rand()%9+1;
			cout<<"arquero se arrojo a:"<<posiciontapada<<endl;
		}
		short getposiciontapada()
		{
			return posiciontapada;
			
		}
		short getposicioninicial()
		{
			return posicioninicial;
		}
		bool logroatajar(player jug)
		{
			return jug.getposiciontiro() == posiciontapada ? true: false;
		}
		float getaltura()
		{
			return altura;
		}
		int getnroatajadas()
		{
			return nroatajadas;
		}

};
class arco{
public:
	void mostrarco()
	{
		cout<<"-----------------------"<<endl;
		cout<<"|   7   |   8   |   9   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|   4   |   5   |   6   |"<<endl;
		cout<<"|-------|-------|-------|"<<endl;
		cout<<"|   1   |   2   |   3   |"<<endl;
		cout<<"---------------------------"<<endl;
	}
	void dibujarTiro(int jug, int aa) {
		char dibujar[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; //matriz de caracteres espacio ' '
		int filaJugador = (9 - jug) / 3;
		int colJugador = (jug - 1) % 3;
		int filaArquero = (9 - aa) / 3;
		int colArquero = (aa - 1) % 3;
		dibujar[filaJugador][colJugador] = 'o'; //se marca el tiro 
		dibujar[filaArquero][colArquero] = 'x'; //se marca la atajada
		cout << "  -----------------------" << endl;
		for (int i = 0; i < 3; i++) {
			cout << " |   " << dibujar[i][0] << "   |   " << dibujar[i][1] << "   |   " << dibujar[i][2] << "   |" << endl;
			if (i < 2) {
				cout << " |-------|-------|-------|" << endl;
			}
		}
		
	}
	
};

	
int main(int argc, char *argv[]) {
	srand(static_cast<unsigned int>(time(0)));
	player j1;
	arquero aq;
	int nrodetiros=5;
	arco ar;
	ar.mostrarco();
	cout<<"posicion inicial del arquero:"<<aq.getposicioninicial()<<endl;
	while(nrodetiros>0){
		cout<<"tiros restantes:"<<nrodetiros<<endl;
	    j1.patear();
		aq.atajar();
	    if(aq.logroatajar(j1.getposiciontiro()))
	    {
		    cout<<"no fue gol, has perdido"<<endl;
		    aq.nroatajadas++;
		    return 0;
	    }
	    else{
		    cout<<"gol"<<endl;
		    j1.nrogoles++;
	    }
		nrodetiros--;
	}
	cout<<"felisidades, lograste marcar:"<<" "<<j1.getnrogoles()<<" "<<"goles"<<endl;
	cout<<"/////"<<endl;
	cout<<"goles:"<<j1.getnrogoles()<<",atajadas:"<<aq.getnroatajadas()<<endl;
	
	return 0;
}

