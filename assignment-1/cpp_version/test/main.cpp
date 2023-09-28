#include <iostream>
#include "BuffonNeedle.hpp"
#include "ThrowingDarts.hpp"

int main() {
    Buffon::writeDataFile(200, 100000, 2, 3);
    ThrowingDarts::writeDataFile(200, 100000);

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        // Dessiner le graphe des données
                // Ajouter une flèche horizontale pour π (pi)
        fprintf(gnuplotPipe, " set arrow from graph 0,first 3.141592 to graph 1,first 3.141592 nohead lc rgb \"#000000\" front\n");  
        fprintf(gnuplotPipe, "plot 'throwingData.dat' with lines title 'Throwing Darts', ");
        fprintf(gnuplotPipe, "'buffonData.dat' with lines linecolor rgb 'red' title 'Buffon Method'\n");
        fclose(gnuplotPipe);
    } else {
        perror("Erreur lors de l'ouverture de gnuplot.");
    }

    return 0;
}