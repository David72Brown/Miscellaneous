#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

unsigned int Factorial(unsigned int n)
{
    /*  Static variables in a function retain their values between function calls.
        For recursive functions like this (i.e. Factorial() calls itself), there is only one RecursionCount variable stored anywhere,
        so any iteration of running this function will see the same value stored in that variable.
        Below, we used RecursionCount to check how many levels of recursion we have (i.e. how many nested calls to Factorial()).
        If it gets to 100 then we've probably got a bug somewhere and we're in an infinite loop.
    */
    static unsigned int RecursionCount = 0;
    unsigned int Answer;

    RecursionCount += 1;
    assert(RecursionCount < 100);

    if (n < 2)
    {
        Answer = 1;
    }
    else
    {
        // Now recursively call this Factorial() function again but now on a smaller number.
        Answer = n * Factorial(n - 1);
    }
    RecursionCount -= 1;
    return Answer;

    // The algorithm above works but it is inefficient because function calls involve lots of stack activity.
    // How could you write the Factorial() function without recursion?
}

void TestFactorialCalcs(void)
{
    unsigned int x, result;

    for (x = 0; x < 1 || x > 12; )
    {
        cout << "Enter number for factorial calculation [1-12 only]: ";
        cin >> x;
    }
    result = Factorial(x);
    cout << "Factorial(" << x << ") = " << result << endl;
}

bool CheckPistonsWorking(void)
{
    return false;
}

bool PerformVitalProcessAndCheckWorkedOK(void)
{
    return true;
}

void DemoIfsAndLoops(void)
{
    // Check user's input and tell user about the number.
    int num;
    cout << "Enter a number:\n";
    cin >> num;
    if (num < 5)
        cout << "Less than 5\n\n";        // <--- Note to David: Can add another cout after this line to demonstrate need for {}.
    else if (num < 20)
        cout << "Less than 20\n\n";
    else
        cout << "20 or more.\n\n";

    // Order of evaluation.
    bool a = true, b = true;
    if (a || b)
    {
        cout << "a || b = true\n";
    }
    else
    {
        cout << "a || b = false\n";
    }
    cout << "a && b = " << ((a && b) ? "true" : "false") << endl;     // This is a quick way of embedding a conditional in a statement: x = condition ? 1 : 2;
    // There is a defect in the IF statement below...
    if (CheckPistonsWorking() && PerformVitalProcessAndCheckWorkedOK())
    {
        cout << "Pistons all good, vital process performed and working OK.\n";
    }
    else
    {
        cout << "Either pistons not working or vital process failed when performed.\n";
    }

    // Do-while and While loop.
    int x[20];
    int i, NumValues = 0;
    cout << "Enter some values (with <Return> after each one), ending with 0:" << endl;
    // Start inputing values into x[0] onwards.
    do
    {
        cin >> x[NumValues];
        NumValues++;
    } while (x[NumValues - 1] != 0);
    // The last value we inputed was 0, which was just the user telling us there are no more values, so ignore that last one:
    NumValues--;
    cout << "Values are: ";
    i = 0;
    while (i < NumValues)
    {
        cout << " " << x[i];
        i = i + 1;
    }
    cout << endl << endl;

    // For loop.
    int NextVal;
    cout << "Enter some values (with <Return> after each one), ending with 0:" << endl;
    cin >> NextVal;
    for (NumValues = 0; NextVal != 0; NumValues++)  // Always initialise NumValues (e.g.) in FOR loop, not just at top of function.
    {
        x[NumValues] = NextVal;
        cin >> NextVal;
    }
    cout << "Values are: ";
    i = 0;
    for (i = 0; i < NumValues; i++)
    {
        cout << " " << x[i];
    }
    cout << endl << endl;
}

void OptimizeForLoop(void)
{
    int i;

    /*  This outputs all numbers whose square is < 100, i.e. it will show:  0 * 0 = 0
                                                                            1 * 1 = 1
                                                                            2 * 2 = 4
                                                                            3 * 3 = 9
                                                                            ...
                                                                            9 * 9 = 81
    */
    cout << "Here are some squares <100 : " << endl;
    for (i = 0; i < sqrt(100); i++)
    {
        cout << i << " * " << i << " = " << i * i << endl;
    }
    cout << endl;
    // The FOR loop above isn't very efficient. How can it be improved?
    // Hint: sqrt() is computationally expensive (it takes a long time).
}

void IncreaseBy7_PassByValue(int x)
{
    x = x + 7;
}

int IncreaseBy7_ReturnResult(int x)
{
    x = x + 7;
    return x;
}

void IncreaseBy7_PassByPointer(int *pX)
{
    *pX = *pX + 7;
}

void IncreaseBy7_PassByReference(int &x)
{
    x = x + 7;
}

void DemoPassByValPtrOrRef()
{
    int x;

    // We want to increase x by 7.
    x = 2;
    cout << "x starts as " << x << endl;
    IncreaseBy7_PassByValue(x);
    // Has it worked?
    cout << "x is now " << x << endl << endl;

    // Try this next.
    x = 2;
    cout << "x starts as " << x << endl;
    x = IncreaseBy7_ReturnResult(x);
    // Has it worked?
    cout << "x is now " << x << endl << endl;

    // Try this next.
    x = 2;
    cout << "x starts as " << x << endl;
    IncreaseBy7_PassByPointer(&x);
    // Has it worked?
    cout << "x is now " << x << endl << endl;

    // Try this next.
    x = 2;
    cout << "x starts as " << x << endl;
    IncreaseBy7_PassByReference(x);
    // Has it worked?
    cout << "x is now " << x << endl << endl;
}

void TestPreAndPostIncs(void)
{
    // Step through this code to see what the pre-increment (or decrement) and post-increment operators do on integers, chars and pointers.
    unsigned int x;
    unsigned char c;

    x = 5;
    x++;
    ++x;
    x += 40;    // x = x + 40
    x -= 3;
    x = 0;
    x--;    // What happens to this UNSIGNED int when it is decremented below 0?

    c = 255;
    c--;
    ++c;
    c += 1; // What happens when c is incremented above 255, which is the largest value an unsigned char can hold?

    // What's the difference between x++ and ++x;
    // The post-inc (x++) evaluates the expression containing x before incrementing x.
    // The pre-inc (++x) does it the other way around.
    int a = 1, b = 2;
    a = b++;    // The expression to the right of the = sign is evaluated using the current value of b and is then assigned to a.
                //  Only then is b incremented.
    a = ++b;    // Here, b is incremented before its value is assigned to a.

    // What about inc/decrementing pointers to variables?
    int SeveralInts[] = { 10, 20, 30, 40, 50 };
    int *p = &SeveralInts[2];
    p++;    // Note that p doesn't move on by just 1 byte, which is what you would expect if its value simply increased by 1.
    --p;    // Pre/post incs/decs on pointers increase/decrease them by the size of the type of variable they are pointing to.
    p += 2;
    p += 5; // What happens when it points to something beyond the end of the array?

    // What about inc/decrementing pointers to structures?
    typedef struct {
        int x;
        bool b;
        char c;
    } tData;
    tData DataArray[] = {
        {  3,  true, 'g' },
        { 13,  true, 'Z' },
        {  7, false, '$' } };
    tData *pDataItem = &DataArray[1];
    pDataItem += 1; // This causes the pointer pDataItem to skip forward several bytes so is points to the next structure in the array.
}

int main()
{
    // Uncomment the thing you want to work on:
    // DemoIfsAndLoops();
    // OptimizeForLoop();
    // TestFactorialCalcs();
    TestPreAndPostIncs();
    DemoPassByValPtrOrRef();
}
