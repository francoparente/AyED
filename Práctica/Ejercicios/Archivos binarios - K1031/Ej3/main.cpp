#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

/*3. Dados dos archivos de enteros confeccione un programa que guarde
en un tercer archivo el contenido de ambos intercalado de a un número.*/

int main()
{
    setlocale(LC_ALL, "");

    int v1[]={1,3,5,7,9};
    int v2[]={2,4,6,8};

    FILE*f1;
    f1=fopen("archivo1_ej3","wb");
    fwrite(v1,sizeof(int),5,f1);
    fseek (f1, 1, SEEK_SET);

    for(int i=0; i<5; i++)
    {
        fread (v1, sizeof(int), 1, f1);
        cout << "Valor " << i+1 << " del primer vector: " << v1[i] << endl;
    }
    fclose(f1);
//------------------------------------------------------------------------
    cout<<"----------------------------"<<endl;
    FILE*f2;
    f2=fopen("archivo2_ej3","wb");
    fwrite(v2,sizeof(int),4,f2);
    fseek (f2, 1, SEEK_SET);

    for(int j=0; j<4; j++)
    {
        fread (v2, sizeof(int), 1, f2);
        cout << "Valor " << j+1 << " del segundo vector: " << v2[j] << endl;
    }
    fclose(f2);
//------------------------------------------------------------------------
    FILE*f3;
    f1=fopen("archivo1_ej3","rb");
    f2=fopen("archivo2_ej3","rb");
    f3=fopen("archivo3_ej3","wb");
    fseek (f1, 1, SEEK_SET);
    fseek (f2, 1, SEEK_SET);

    int x1=0,x2=0;

    for(int k=0; k<9; k++)
    {
        if(k%2==0 || k==0)
        {
            fread(&x1,sizeof(int),1,f1);
            fwrite(&x1,sizeof(int),1,f3);
        }
        else
        {
            fread(&x2,sizeof(int),1,f2);
            fwrite(&x2,sizeof(int),1,f3);
        }
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
//------------------------------------------------------------------------
    cout << "---------------------------" << endl;
    cout << "Los valores del tercer archivo son:" << endl;

    f3=fopen("archivo_ej3","rb");
    fseek (f3, 1, SEEK_SET);
    int x=0;

    for(int g=0; g<9; g++)
    {
        cout << "Valor " << g+1 << ": " << x << endl;
        fread (&x, sizeof(int), 1, f3);
    }
    fclose(f3);

    return 0;
}
