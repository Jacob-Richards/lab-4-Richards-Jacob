#include <stdio.h>

// Function to convert temperatures between Fahrenheit, Celsius, and Kelvin
double convert_temperature(double temp, char input_scale, char target_scale) {
    double temp_in_celsius;

    // Convert from input scale to Celsius first
    if (input_scale == 'C') {
        temp_in_celsius = temp;
    } else if (input_scale == 'F') {
        temp_in_celsius = (temp - 32) * 5 / 9; // Convert Fahrenheit to Celsius
    } else if (input_scale == 'K') {
        temp_in_celsius = temp - 273.15; // Convert Kelvin to Celsius
    } else {
        printf("Invalid input scale.\n");
        return 0;
    }

    // Convert from Celsius to target scale
    if (target_scale == 'C') {
        return temp_in_celsius;
    } else if (target_scale == 'F') {
        return (temp_in_celsius * 9 / 5) + 32; // Convert Celsius to Fahrenheit
    } else if (target_scale == 'K') {
        return temp_in_celsius + 273.15; // Convert Celsius to Kelvin
    } else {
        printf("Invalid target scale.\n");
        return 0;
    }
}

// Function to categorize the temperature and provide a weather advisory
void provide_weather_advisory(double temp_celsius) {
    if (temp_celsius < 0) {
        printf("Category: Freezing\n");
        printf("Advisory: It's extremely cold. Stay warm and avoid staying outside for too long.\n");
    } else if (temp_celsius >= 0 && temp_celsius < 10) {
        printf("Category: Cold\n");
        printf("Advisory: Wear a jacket to stay warm.\n");
    } else if (temp_celsius >= 10 && temp_celsius < 25) {
        printf("Category: Comfortable\n");
        printf("Advisory: The weather is pleasant. Enjoy your day!\n");
    } else if (temp_celsius >= 25 && temp_celsius < 35) {
        printf("Category: Hot\n");
        printf("Advisory: Stay hydrated and avoid prolonged sun exposure.\n");
    } else {
        printf("Category: Extreme Heat\n");
        printf("Advisory: It's very hot. Stay indoors and keep cool.\n");
    }
}

int main() {
    double temp;
    char input_scale, target_scale;
    
    printf("Enter the temperature value: ");
    scanf("%lf", &temp);

    // Prompt the user for the input scale
    printf("Enter the temperature scale of the input value (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &input_scale);

    // Prompt the user for the target scale
    printf("Enter the target temperature scale (C for Celsius, F for Fahrenheit, K for Kelvin): ");
    scanf(" %c", &target_scale);

    // Convert the temperature
    double converted_temp = convert_temperature(temp, input_scale, target_scale);
    printf("Converted temperature: %.2lf %c\n", converted_temp, target_scale);

    // Convert the temperature to Celsius for categorization
    double temp_in_celsius = convert_temperature(temp, input_scale, 'C');
    provide_weather_advisory(temp_in_celsius);

    return 0;
}