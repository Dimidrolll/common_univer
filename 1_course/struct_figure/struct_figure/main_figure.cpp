#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
using namespace std;
union figure{
  int typee;
  char colour[20];
  short int radius;
  int length_quadro;
  float length;
};

void init_figure(figure fig[], int i)
{
  int tyype;
  cout << "¬веди 1, если фигура - circle" << endl;
  cout << "¬веди 2, если фигура - square" << endl;
  cout << "¬веди 3, если фигура - line_s" << endl;
  cin >> tyype;
  fig[i].typee = tyype;
  cout << "¬веди colour фигуры" << endl;
  cin >> fig[i].colour; 
  switch (tyype) {
    case 1:cout << "¬веди радиус circle" << endl;
    cin >> fig[i].radius;break;
    case 2:cout << "¬веди длину стороны square" << endl;
    cin >> fig[i].length_quadro;break;
    case 3:cout << "¬веди длину line_s" << endl;
    cin >> fig[i].length; break;
  }
 /* if (tyype == 1) {
    cout << "¬веди радиус circle" << endl;
    cin >> fig[i].radius;}

   if (tyype == 1) fig[i].typee = "circle";
  
  if (tyype == 2) {
    cout << "¬веди длину стороны square" << endl;
    cin >> fig[i].length_quadro;
    fig[i].typee = "square";
  }
  if (tyype == 3) {
    cout << "¬веди длину line_s" << endl;
    cin >> fig[i].length;
    fig[i].typee = "line_s";
  }*/
}
void main()
{
  setlocale(0,"");
  int n;
  fstream f_bin;
  figure fig[99];
  cout << "¬веди число фигур." << endl;
  cin >> n;
  for (int i = 0; i < n; ++i)
    init_figure(fig ,i);
  f_bin.open("struct.dat",ios::binary|ios::out|ios::trunc|ios::in);
  /*for (int i = 0; i < n; ++i){
    f_bin >> fig[i].typee >> fig[i].colour;
    if (fig[i].typee == "circle") f_bin >> fig[i].radius;
    if (fig[i].typee == "square") f_bin >> fig[i].length_quadro;
    if (fig[i].typee == "line_s") f_bin >> fig[i].length;
  }
  for (int i = 0; i < n; ++i){
    f_bin << fig[i].typee << fig[i].colour;
    if (fig[i].typee == "circle") f_bin << fig[i].radius;
    if (fig[i].typee == "square") f_bin << fig[i].length_quadro;
    if (fig[i].typee == "line_s") f_bin << fig[i].length;
  }*/
  //
  f_bin.seekg(0,0);f_bin.seekg(0,0);
  for (int i = 0; i < n; ++i){
    f_bin.write((char*) &fig[i].typee, sizeof(fig[i].typee)); f_bin.write((char*) &fig[i].colour, sizeof(fig[i].colour)); //fig[i].colour
    if (fig[i].typee == 1) f_bin.write((char*) &fig[i].radius, sizeof(fig[i].radius));
    if (fig[i].typee == 2) f_bin.write((char*) &fig[i].length_quadro, sizeof(fig[i].length_quadro));
    if (fig[i].typee == 3) f_bin.write((char*) &fig[i].length, sizeof(fig[i].length));
  }
  f_bin.seekg(0,0);f_bin.seekg(0,0);
  for (int i = 0; i < n; ++i){
    f_bin.read((char*) &fig[i].typee, sizeof(fig[i].typee)); f_bin.read((char*) &fig[i].colour, sizeof(fig[i].colour));
    if (fig[i].typee == 1) f_bin.read((char*) &fig[i].radius, sizeof(fig[i].radius));
    if (fig[i].typee == 2) f_bin.read((char*) &fig[i].length_quadro, sizeof(fig[i].length_quadro));
    if (fig[i].typee == 3) f_bin.read((char*) &fig[i].length, sizeof(fig[i].length));
  }
  for (int i = 0; i < n; ++i){
    if (fig[i].typee == 1) for (int j = 0; j < 6; ++j) cout << fig[i].colour[j]; 
    if (fig[i].typee == 2) for (int j = 0; j < 6; ++j) cout << fig[i].colour[j];
    if (fig[i].typee == 3) for (int j = 0; j < 6; ++j) cout << fig[i].colour[j];
    if (fig[i].typee == 1) cout << "circle";
    if (fig[i].typee == 2) cout << "square";
    if (fig[i].typee == 3) cout << "line_s";
    //cout << fig[i].colour;
    if (fig[i].typee == 1) cout << fig[i].radius << endl;
    if (fig[i].typee == 2) cout << fig[i].length_quadro << endl;
    if (fig[i].typee == 3) cout << fig[i].length << endl;
  }
  f_bin.close();
  getch();
}