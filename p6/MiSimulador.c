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
	/* Escriu aqui el teu codi */
	int i;
    for (i = 0; i < 128; ++i){
        v[i].validesa = 0;
        v[i].tag = 0;
    }


}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	

	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	

	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */

	byte = 0b000000000000000000000000000011111 & address;
    bloque_m = address/0b100000;
    linea_mc = bloque_m & 0b0000000000000000000001111111;
    tag = bloque_m/0b10000000;
    
    if(!LE){
	    if (v[linea_mc].validesa){
	        if (v[linea_mc].tag == tag){
	            miss = 0;
	            replacement = 0;
	            tag_out = 0;
	            lec_mp = 0;
	            mida_lec_mp = 0;
	            esc_mp = 0;
	            mida_esc_mp = 0;
	        }
	        else{
	            miss = 1;
	            tag_out = v[linea_mc].tag;
	            replacement = 1;
	            v[linea_mc].tag = tag;
	            lec_mp = 1;
	            mida_lec_mp = 32;
	            esc_mp = 0;
	            mida_esc_mp = 0;
	        }
	    }
	    else{
	        miss = 1;
	        replacement = 0;
	        tag_out = 0;
	        v[linea_mc].tag = tag;
	        v[linea_mc].validesa = 1;
	        lec_mp = 1;
	        mida_lec_mp = 32;
	        esc_mp = 0;
	        mida_esc_mp = 0;
	    }
	}
	else{
		if (v[linea_mc].validesa){
	        if (v[linea_mc].tag == tag){
	            miss = 0;
	            replacement = 0;
	            tag_out = 0;
	            lec_mp = 0;
	            mida_lec_mp = 0;
	            esc_mp = 1;
	            mida_esc_mp = 1;
	        }
	        else{
	            miss = 1;
	            tag_out = v[linea_mc].tag;
	            replacement = 1;
	            v[linea_mc].tag = tag;
	            lec_mp = 1;
	            mida_lec_mp = 32;
	            esc_mp = 1;
	            mida_esc_mp = 1;
	        }
	    }
	    else{
	        miss = 1;
	        replacement = 0;
	        tag_out = 0;
	        v[linea_mc].tag = tag;
	        v[linea_mc].validesa = 1;
	        lec_mp = 0;
	        mida_lec_mp =4;
	        esc_mp = 1;
	        mida_esc_mp = 1;
	    }
	}


	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
  
  
}
