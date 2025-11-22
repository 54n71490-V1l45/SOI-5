# SOI-5
Para la práctica 5 de SOI

En cada carpeta "Ej" se almacena la ejecución (copiada desde la terminal) y archivos con los mapas de memoria en cada instante. Cada vez que haya una pausa en la que tengas que pulsar la tecla enter deberías guardar el mapa de memoria en la carpeta del ejercicio correspondiente. Esto se puede hacer mediente el siguiente comando:
cp /proc/_PID_/maps /_ruta_/_de_/_donde_/_debe_/_estar_/SOI-5/Ej
Teniendo que cambiar _PID_ por el pid del proceso y _ruta de donde debe estar_ por la ruta donde está la carpeta, además de añadir el número del ejercicio a la carpeta Ej (para que se guarde donde toca), como se hace muchas veces eso, después de cada _cp..._ se debe renombrar el nuevo archivo que ha aparecedo en la carpeta Ej... para darle un nombre más explicativo y para que no se pierda cuando se haga el siguiente cp... 