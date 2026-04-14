#include <stdio.h>
#include <math.h>

float carnot_efficiency(float Th, float Tc) {
    return 1 - (Tc / Th);
}

float otto_efficiency(float r, float gamma) {
    return 1 - (1 / pow(r, gamma - 1));
}

float diesel_efficiency(float r, float rc, float gamma) {
    return 1 - ((1 / pow(r, gamma - 1)) * 
               ((pow(rc, gamma) - 1) / (gamma * (rc - 1))));
}

int main() {
    int choice;
    float Th, Tc, r, rc, gamma, eff;

    printf("Thermodynamic Cycle Calculator\n");
    printf("1. Carnot Cycle\n");
    printf("2. Otto Cycle\n");
    printf("3. Diesel Cycle\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter Hot Temperature (K): ");
            scanf("%f", &Th);
            printf("Enter Cold Temperature (K): ");
            scanf("%f", &Tc);
            eff = carnot_efficiency(Th, Tc);
            printf("Carnot Efficiency = %.2f %%\n", eff * 100);
            break;

        case 2:
            printf("Enter Compression Ratio: ");
            scanf("%f", &r);
            printf("Enter Gamma (Cp/Cv): ");
            scanf("%f", &gamma);
            eff = otto_efficiency(r, gamma);
            printf("Otto Efficiency = %.2f %%\n", eff * 100);
            break;

        case 3:
            printf("Enter Compression Ratio: ");
            scanf("%f", &r);
            printf("Enter Cut-off Ratio: ");
            scanf("%f", &rc);
            printf("Enter Gamma (Cp/Cv): ");
            scanf("%f", &gamma);
            eff = diesel_efficiency(r, rc, gamma);
            printf("Diesel Efficiency = %.2f %%\n", eff * 100);
            break;

        default:
            printf("Invalid Choice\n");
    }

    return 0;
}
