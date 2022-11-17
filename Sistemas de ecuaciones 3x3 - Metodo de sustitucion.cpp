/////Code By ErickNewBieDev
/////GitHub: https://github.com/ErickNewbieDev
////itch.io: https://ericknewbiedev.itch.io/
////Contact: ericknewbiedev@protonmail.com
#include <iostream>
#include <string>
using namespace std;

void Ecuaciones();
void ImprimirEstructura();
void Despeje();

int coeficientes[5][3];
int Vx = 0, Vy = 0, Vz = 0;

int main() {
//Se usa en caso de no querer introducir los datos uno a uno, se le asignan los valores a cada coeficiente desde el codigo, se necesita desactivar antes el metodo Ecuaciones
/*
coeficientes[0][0]=2;coeficientes[1][0]=3;coeficientes[2][0]=4;coeficientes[3][0]=0;coeficientes[4][0]=20;
coeficientes[0][1]=3;coeficientes[1][1]=-5;coeficientes[2][1]=-1;coeficientes[3][1]=0;coeficientes[4][1]=-10;
coeficientes[0][2]=-1;coeficientes[1][2]=2;coeficientes[2][2]=-3;coeficientes[3][2]=0;coeficientes[4][2]=-6;*/

Ecuaciones();
ImprimirEstructura();
Despeje();

cout<<"Solucion:"<<endl;
cout<<"X = "<<Vx<<"    Y = "<<Vy<<"    Z = "<<Vz<<endl;

return 0;
}

void Ecuaciones(){
char letras[] = {'X','Y','Z'};
	for(int j=0; j<3; j++){
		cout << "ECUACION "<<(j+1) << endl;
			for(int i=0; i<5; i++){
				if(i<3){
				cout << "Ingrese el coeficiente de "<<letras[i]<<" en la ecuacion "<<(j+1)<<": ";
				cin >> coeficientes[i][j];
				}
				if(i==3){
				cout << "Ingrese el termino independiente de la ecuacion "<<(j+1)<<": ";
				cin >> coeficientes[i][j];
				}
				if(i==4){
				cout << "Ingrese la igualdad de la ecuacion "<<(j+1)<<": ";
				cin >> coeficientes[i][j];
			}
		}cout<<endl;
	} cout<<endl;
}

void ImprimirEstructura(){
cout<<"Sistema de ecuaciones:"<<endl;
for(int i=0; i<3; i++){
cout <<"{ "<<"("<<coeficientes[0][i]<<"X) + ("<<coeficientes[1][i]<<"Y) + ("<<coeficientes[2][i]<<"Z)";
if(coeficientes[3][i]!=0){
cout<<" + ("<<coeficientes[3][i]<<") = "<<coeficientes[4][i]<<endl;
}
else{
cout <<" = "<<coeficientes[4][i]<<endl;
		}
	}cout<<endl;
}

void Despeje(){
cout<<"Procedimiento:"<<endl;
int x[] = {coeficientes[4][0],(-1*coeficientes[1][0]),(-1*coeficientes[2][0]),(-1*coeficientes[3][0]),coeficientes[0][0]};

cout<<"X = [("<<x[0]<<") + ("<<x[1]<<"Y) + ("<<x[2]<<"Z) + ("<<x[3]<<")] / "<<x[4]<<endl;
cout<<endl;

cout<<"("<<coeficientes[0][1]<<") * ([("<<x[0]<<") + ("<<x[1]<<"Y) + ("<<x[2]<<"Z) + ("<<x[3]<<")] / "<<x[4]<<") + ("<<coeficientes[1][1]<<"Y) + ("<<coeficientes[2][1];
cout<<"Z) + ("<<coeficientes[3][1]<<") = "<<coeficientes[4][1]<<endl;
cout<<endl;

int NE1[] = {(coeficientes[0][1]*x[0]),(coeficientes[0][1]*x[1]),(coeficientes[0][1]*x[2]),x[4],(coeficientes[0][1]*x[3])};

cout<<"([("<<NE1[0]<<") + ("<<NE1[1]<<"Y) + ("<<NE1[2]<<"Z) + ("<<NE1[4]<<")] / "<<NE1[3]<<") + ("<<coeficientes[1][1]<<"Y / 1) + ("<<coeficientes[2][1];
cout<<"Z / 1) + ("<<coeficientes[3][1]<<" / 1) = "<<coeficientes[4][1]<<endl;
cout<<endl;

int NE2[] = {NE1[0],NE1[1],NE1[2],(coeficientes[1][1]*NE1[3]),(coeficientes[2][1]*NE1[3]),NE1[3],coeficientes[4][1],NE1[4],coeficientes[3][1]};

cout<<"[("<<NE2[0]<<") + ("<<NE2[1]<<"Y) + ("<<NE2[2]<<"Z) + ("<<NE2[7]<<") + ("<<NE2[3]<<"Y) + ("<<NE2[4]<<"Z) + ("<<NE2[8]<<")] / "<<NE2[5]<<" = "<<NE2[6]<<endl;
cout<<endl;

int NE3[] = {(NE2[1]+NE2[3]),(NE2[2]+NE2[4]),(NE2[6]*NE2[5]),(NE2[0]*-1),(NE2[7]*-1),(NE2[8]*-1)};

cout<<"("<<NE3[0]<<"Y) + ("<<NE3[1]<<"Z) = ("<<NE3[2]<<") + ("<<NE3[3]<<") + ("<<NE3[4]<<") + ("<<NE3[5]<<")"<<endl;
cout<<endl;

int NE4[] = {NE3[0],NE3[1],(NE3[2]+NE3[3]+NE3[4]+NE3[5])};//Ecuacion A

cout<<"("<<NE4[0]<<"Y) + ("<<NE4[1]<<"Z) = ("<<NE4[2]<<") <---------- Ec. A"<<endl;
cout<<"\n"<<endl;

cout<<"("<<coeficientes[0][2]<<") * ([("<<x[0]<<") + ("<<x[1]<<"Y) + ("<<x[2]<<"Z) + ("<<x[3]<<")] / "<<x[4]<<") + ("<<coeficientes[1][2]<<"Y) + ("<<coeficientes[2][2];
cout<<"Z) + ("<<coeficientes[3][2]<<") = "<<coeficientes[4][2]<<endl;
cout<<endl;

int NE5[] = {(coeficientes[0][2]*x[0]),(coeficientes[0][2]*x[1]),(coeficientes[0][2]*x[2]),x[4],(coeficientes[0][2]*x[3])};

cout<<"([("<<NE5[0]<<") + ("<<NE5[1]<<"Y) + ("<<NE5[2]<<"Z) + ("<<NE5[4]<<")] / "<<NE5[3]<<") + ("<<coeficientes[1][2]<<"Y / 1) + ("<<coeficientes[2][2];
cout<<"Z / 1) + ("<<coeficientes[3][2]<<" / 1) = "<<coeficientes[4][2]<<endl;
cout<<endl;

int NE6[] = {NE5[0],NE5[1],NE5[2],coeficientes[3][2],(coeficientes[1][2]*NE5[3]),(coeficientes[2][2]*NE5[3]),coeficientes[3][2],NE5[3],coeficientes[4][2]};

cout<<"[("<<NE6[0]<<") + ("<<NE6[1]<<"Y) + ("<<NE6[2]<<"Z) + ("<<NE6[3]<<") + ("<<NE6[4]<<"Y) + ("<<NE6[5]<<"Z) + ("<<NE6[6]<<")] / "<<NE6[7]<<" = "<<NE6[8]<<endl;
cout<<endl;

int NE7[] = {(NE6[1]+NE6[4]),(NE6[2]+NE6[5]),(NE6[8]*NE6[7]),(NE6[0]*-1),(NE6[3]*-1),(NE6[6]*-1)};

cout<<"("<<NE7[0]<<"Y) + ("<<NE7[1]<<"Z) = ("<<NE7[2]<<") + ("<<NE7[3]<<") + ("<<NE7[4]<<") + ("<<NE7[5]<<")"<<endl;
cout<<endl;

int NE8[] = {NE7[0],NE7[1],(NE7[2]+NE7[3]+NE7[4]+NE7[5])};//Ecuacion B

cout<<"("<<NE8[0]<<"Y) + ("<<NE8[1]<<"Z) = ("<<NE8[2]<<") <---------- Ec. B"<<endl;
cout<<"\n"<<endl;

cout<<"Nuevo sistema de ecuaciones:"<<endl;

cout<<"{ ("<<NE4[0]<<"Y) + ("<<NE4[1]<<"Z) = ("<<NE4[2]<<") <---------- Ec. A"<<endl;
cout<<"{ ("<<NE8[0]<<"Y) + ("<<NE8[1]<<"Z) = ("<<NE8[2]<<") <---------- Ec. B"<<endl;
cout<<"\n"<<endl;

cout<<"Procedimiento."<<endl;

cout<<"("<<NE4[0]<<"Y) + ("<<NE4[1]<<"Z) = ("<<NE4[2]<<")"<<endl;cout<<endl;

int NE9[]={NE4[0],NE4[2],(NE4[1]*-1)};

cout<<"("<<NE9[0]<<"Y) = ("<<NE9[1]<<") + ("<<NE9[2]<<"Z)"<<endl;cout<<endl;

cout<<"Y = [("<<NE9[1]<<") + ("<<NE9[2]<<"Z)] / ("<<NE9[0]<<")"<<endl;cout<<endl;
cout<<"\n"<<endl;

cout<<"("<<NE8[0]<<") * ([("<<NE9[1]<<") + ("<<NE9[2]<<"Z)] / "<<NE9[0]<<") + ("<<NE8[1]<<"Z) = ("<<NE8[2]<<")"<<endl;cout<<endl;

int NE10[] = {(NE8[0]*NE9[1]),(NE8[0]*NE9[2]),NE9[0],NE8[1],NE8[2]};

cout<<"([("<<NE10[0]<<") + ("<<NE10[1]<<"Z)]/"<<NE10[2]<<") + ("<<NE10[3]<<"Z / 1) = ("<<NE10[4]<<")"<<endl;cout<<endl;

int NE11[] = {NE10[0],NE10[1],(NE10[2]*NE10[3]),NE10[2],NE10[4]};

cout<<"[("<<NE11[0]<<") + ("<<NE11[1]<<"Z) + ("<<NE11[2]<<"Z)] / ("<<NE11[3]<<") = ("<<NE11[4]<<")"<<endl;cout<<endl;

int NE12[] = {NE11[0],NE11[1],NE11[2],(NE11[3]*NE11[4])};

cout<<"("<<NE12[0]<<") + ("<<NE12[1]<<"Z) + ("<<NE12[2]<<"Z) = ("<<NE12[3]<<")"<<endl;cout<<endl;

int NE13[] = {(NE12[1]+NE12[2]),NE12[3],(NE12[0]*-1)};

cout<<"("<<NE13[0]<<"Z) = ("<<NE13[1]<<") + ("<<NE13[2]<<")"<<endl;cout<<endl;

int NE14[] = {(NE13[1]+NE13[2]),NE13[0]};

cout<<"Z = ("<<NE14[0]<<") / ("<<NE14[1]<<")"<<endl;cout<<endl;

Vz = NE14[0]/NE14[1];

cout<<"Z = "<<Vz<<" <--------Valor de Z"<<endl;
cout<<"\n"<<endl;

cout<<"Y = [("<<NE9[1]<<") + ("<<NE9[2]<<") * ("<<Vz<<")] / ("<<NE9[0]<<")"<<endl;cout<<endl;

int NE15[] = {NE9[1],(NE9[2]*Vz),NE9[0]};

cout<<"Y = [("<<NE15[0]<<") + ("<<NE15[1]<<")] / ("<<NE15[2]<<")"<<endl;cout<<endl;

int NE16[] = {(NE15[0]+NE15[1]),NE15[2]};

cout<<"Y = ("<<NE16[0]<<") / ("<<NE16[1]<<")"<<endl;cout<<endl;

Vy = NE16[0]/NE16[1];

cout<<"Y = "<<Vy<<" <--------Valor de Y"<<endl;
cout<<"\n"<<endl;

cout<<"X = [("<<x[0]<<") + [("<<x[1]<<") * ("<<Vy<<")] + [("<<x[2]<<") + ("<<Vz<<")] + ("<<x[3]<<")] / "<<x[4]<<endl;cout<<endl;
cout<<endl;

int NE17[] = {x[0],(x[1]*Vy),(x[2]*Vz),x[3],x[4]};

cout<<"X = [("<<NE17[0]<<") + ("<<NE17[1]<<") + ("<<NE17[2]<<") + ("<<NE17[3]<<")] / "<<NE17[4]<<endl;cout<<endl;

int NE18[] = {(NE17[0]+NE17[1]+NE17[2]+NE17[3]),NE17[4]};

cout<<"X = ("<<NE18[0]<<") / "<<NE18[1]<<endl;cout<<endl;

Vx = NE18[0]/NE18[1];

cout<<"X = "<<Vx<<" <--------Valor de X"<<endl;
cout<<"\n"<<endl;

}
