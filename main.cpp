#include <iostream>
#include <vector>
#include <string>
using namespace std;


class persona{
	private: 
	   int dinero;
	   string nombre;
	public:
	    persona(string _nombre):nombre{_nombre}, dinero{0} {}
	    void entregar(int num, persona* a){
		    a->dinero += num;
         	dinero-= num;
	    }
    string get_name(){
	        return nombre;
	    }
	    int get_dinero(){
	        return dinero;
	    }
};

int find( persona** a, string per, int cant){
    for(int i = 0; i < cant; i++){
        if(a[i]->get_name() == per){
            return i;
        }
    }
}

int main(){
    bool o = true;

	int cant;
	string p;
	while(cin >> cant) {
        if(!o)
            cout << endl;
        o = false;
        auto **arr = new persona *[cant];
        for (int i = 0; i < cant; i++) {
            cin >> p;
            arr[i] = new persona(p);
        }
        int index;
        int entr;
        int money;
        int repartido = 0;
        for (int i = 0; i < cant; i++) {
            cin >> p;
            index = find(arr, p, cant);
            cin >> money;
            cin >> entr;
            int para;
            string entregados;
            if (entr != 0)
                repartido = money / entr;
            else
                repartido = 0;
            for (int j = 0; j < entr; j++) {
                cin >> entregados;
                para = find(arr, entregados, cant);
                arr[index]->entregar(repartido, arr[para]);
            }
        }
        for (int i = 0; i < cant; i++) {
            cout << arr[i]->get_name() << " " << arr[i]->get_dinero() << endl;
        }

    }
}
