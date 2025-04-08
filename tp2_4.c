#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Cant_PC 6

struct compu {
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
   };

   char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core","Pentium"};

   void cargar(struct compu pcs[], int cantidad){
    for (int i = 0; i < cantidad ; i++)
    {
        pcs[i].velocidad = 1 + rand() % 3;  // 1 a 3
        pcs[i].anio = 2015 + rand() % 10;   // 2015 a 2024
        pcs[i].cantidad_nucleos = 1 + rand() % 8;   // 1 a 8
        int indice_tipo = rand () % 6;
        pcs[i].tipo_cpu= tipos[indice_tipo];    // Apunta a cadena del arreglo    
    }  
   }



   void listarPCs(struct compu pcs[], int cantidad){
    for(int i=0; i< cantidad; i++)
    {
        printf("PC #%d:\n", i + 1);
        printf("Velocidad: %d GHz\n",pcs[i].velocidad);
        printf("Anio: %d\n",pcs[i].anio);    
        printf("Nucleos: %d\n",pcs[i].cantidad_nucleos);    
        printf("Tipo CPU: %s\n",pcs[i].tipo_cpu);
        printf("\n");    
    }
   }


   void mostrarMasVieja(struct compu pcs[], int cantidad){
    int indice_viejo=0;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < pcs[indice_viejo].anio)
        {
            indice_viejo =i;
        }
        
    }
    printf("PC mas vieja\n");
    printf("  Velocidad: %d GHz\n", pcs[indice_viejo].velocidad);
    printf("  Anio: %d\n", pcs[indice_viejo].anio);
    printf("  Nucleos: %d\n", pcs[indice_viejo].cantidad_nucleos);
    printf("  Tipo CPU: %s\n", pcs[indice_viejo].tipo_cpu);
    printf("\n");
   }

   void mostrarMasVeloz(struct compu pcs[], int cantidad){
    int velocidad=0;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad> pcs[velocidad].velocidad)
        {
            velocidad = i;
        }
        
    }
    printf(" PC mas rapida\n");
    printf("  Velocidad: %d GHz\n", pcs[velocidad].velocidad);
    printf("  Anio: %d\n", pcs[velocidad].anio);
    printf("  Nucleos: %d\n", pcs[velocidad].cantidad_nucleos);
    printf("  Tipo CPU: %s\n", pcs[velocidad].tipo_cpu);
    printf("\n");

   }


int main (){
    srand(time(NULL));

    struct compu pcs[Cant_PC];

    cargar(pcs,Cant_PC); //generar la PCs aleatorias 
    
    listarPCs(pcs,Cant_PC); //mostrar las PCs aleatorias

    mostrarMasVieja(pcs,Cant_PC); //mostrar la mas vieja

    mostrarMasVeloz(pcs,Cant_PC);   //mostrar la mas veloz

    return 0;
}