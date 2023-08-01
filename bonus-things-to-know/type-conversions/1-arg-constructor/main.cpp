class Celsius
{
private:
    double temperatureCelsius;

public:
    explicit Celsius(double tempCelsius) : temperatureCelsius(tempCelsius) {}
};

int main()
{
    double celsiusValue = 25.0;
    Celsius c(celsiusValue); 
    // One-argument constructor is implicitly called here to convert double to Celsius object
    
    return 0;
}
