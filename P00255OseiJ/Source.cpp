#include<iostream>
#include<cmath>

using namespace std;

struct ComplexNumber {
    double real;
    double imag;
};

ComplexNumber addComplexNumber(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;

    return result;
}
ComplexNumber subtractComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}
ComplexNumber multiplyComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real * num2.real - num1.imag * num2.imag;
    result.imag = num1.real * num2.imag + num1.imag * num2.real;

    return result;
}
ComplexNumber divideComplexNumbers(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    double division = num2.real * num2.real + num2.imag* num2.imag;
    result.real = ((num1.real * num2.real) + (num1.imag * num2.imag)) / division;
    result.imag = ((num1.imag * num2.real) - (num1.real * num2.imag)) / division;
    return result;
}

void displayComplexNumber(ComplexNumber num) {
    cout << num.real << " " << num.imag<< "i" << endl;
}

int main() {
    char userInput;
    ComplexNumber num1;
    ComplexNumber num2;
    ComplexNumber result;
    cout << "**** Complex Numbers ****" << endl;

    do {
        cout << "Enter 1st complex number real and imaginary parts separated by space: ";
        cin >> num1.real >> num1.imag;
        cout << "\nEnter 2nd complex number real and imaginary parts sepateated by space: ";
        cin >> num2.real >> num2.imag;
        
       while(num2.real == 0 || num2.imag == 0 ) {
       cout << ">>> ERROR: Both Numbers must be non-zero -- try again! <<<" << endl;
       cout << endl;
       cout << "Enter 2nd complex number real and imaginary parts sepateated by space: ";
       cin >> num2.real >> num2.imag;
       
       }
           
      
       cout << endl;
        cout << "Results: " << endl;
        result = addComplexNumber(num1, num2);
        cout << "\tAdditional Results:";
        displayComplexNumber(result);
        result = subtractComplexNumbers(num1, num2);
        cout << "\tSubtraction Results:";
        displayComplexNumber(result);
        cout << "\tMultiplication Results:";
        result = multiplyComplexNumbers(num1, num2);
        displayComplexNumber(result);
        cout << "\tDivision Results:";
        result = divideComplexNumbers(num1, num2);
        displayComplexNumber(result);
        cout << endl<<endl;
        cout << "Run again (y or Y) or any other character to end?";
        cin >> userInput;
        cout << endl;
    } while (userInput == 'y' || userInput == 'Y');

    return 0;
}