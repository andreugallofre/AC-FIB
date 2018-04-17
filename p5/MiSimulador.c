#include "CacheSim.h"

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

struct linea {
   int  validesa;
   int  tag;
}; 

struct linea v[128];

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
    int i;
    for (i = 0; i < 128; ++i){
        v[i].validesa = 0;
        v[i].tag = 0;
    }
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
    
    byte = 0b000000000000000000000000000011111 & address;
    bloque_m = address/0b100000;
    linea_mc = bloque_m & 0b0000000000000000000001111111;
    tag = bloque_m/0b10000000;
    
    if (v[linea_mc].validesa){
        if (v[linea_mc].tag == tag){
            miss = 0;
            replacement = 0;
            tag_out = 0;
        }
        else{
            miss = 1;
            tag_out = v[linea_mc].tag;
            replacement = 1;
            v[linea_mc].tag = tag;
        }
    }
    else{
        miss = 1;
        replacement = 0;
        tag_out = 0;
        v[linea_mc].tag = tag;
        v[linea_mc].validesa = 1;
    }

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
