class Distance
{
private:
    double meters;

public:
    Distance(double meters) : meters(meters) {}

    // Conversion operator from Distance to double (converts meters to double)
    operator double() const
    {
        return meters;
    }
};

int main()
{
    Distance d(1000.0);
    double distanceInMeters = d; // The conversion operator is automatically called here
    return 0;
}
/*
When an object of MyClass is used in a context that requires an object of TargetType, the conversion operator will be automatically invoked to perform the conversion */