double temp_int;
double temp_ext;
int lumino;

bool froid_int(){
	//Retourne true si froid à l'intérieur
}

bool inter_int(){
	//Retourne true si inter à l'intérieur
}

bool inter_ext(){
	//Retourne true si inter à l'extérieur
}

bool froid_int(){
	//Retourne true si froid à l'intérieur
}

bool nuit(){
	//Retourne true si il fait nuit
}

bool soleil(){
	//Retourne true si il fait soleil
}

bool chaud_ext(){
	//Retourne true si chaud à l'extérieur
}

void ouvrir(){
	//Ouvrir le volet
}

void fermer(){
	//Fermer le volet
}

void lame0(){
	//Mettre les lames à 0°
}

void lame90(){
	//Mettre les lames à 90°
}

void lame180(){
	//Mettre les lames à 180°
}

void setup(){

}

void loop(){
	if(froid_int()){
		if(inter_ext()){
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				lame0();
				ouvrir();
			}
		}
		else if(chaud_ext()){
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				lame0();
				ouvrir();
			}
		}
		else{
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				lame0();
				ouvrir();
			}
		}
	}
	else if(inter_int()){
		if(inter_ext()){
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				fermer();
				lame180();
			}
		}
		else{
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				fermer();
				lame90();
			}
		}
	}
	else{
		if(chaud_ext()){
			if(nuit()){
				fermer();
				lame0();
			}
			else if(soleil()){
				fermer();
				lame90();
			}
			else{
				fermer();
				lame180();
			}
		}
		else{
			if(nuit()){
				fermer();
				lame0();
			}
			else{
				lame0();
				ouvrir();
			}
		}
	}
}