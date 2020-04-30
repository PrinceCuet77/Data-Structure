#include <bits/stdc++.h>
using namespace std;

int firstElement = -1, lastElement = -1;

void enqueue(stack < int > &first, int data) {
        if ( firstElement == -1 && lastElement == -1 )
                firstElement = lastElement = data;
        else
                lastElement = data;
        first.push(data);
}

int dequeue(stack < int > &first, stack < int > &second) {
        if ( first.empty() ) {
                if ( second.empty() ) {
                        cout << "Queue is empty" << endl;
                        firstElement = lastElement = -1;
                        return -1;
                }
        } else {
                if ( !second.empty() ) {
                        int value = second.top();
                        second.pop();
                        if ( !second.empty() )
                                firstElement = second.top();
                        else {
                                while ( !first.empty() ) {
                                        second.push(first.top());
                                        first.pop();
                                }
                                if ( !first.empty() )
                                        firstElement = -1;
                                if ( !second.empty() )
                                        firstElement = second.top();
                        }
                        return value;
                }
                if ( second.empty() ) {
                        while ( !first.empty() ) {
                                second.push(first.top());
                                first.pop();
                        }
                }
        }
        int value = second.top();
        second.pop();
        if ( !second.empty() )
                firstElement = second.top();
        return value;
}

bool isEmpty(stack < int > first, stack < int > second) {
        return first.empty() && second.empty();
}

// ---------------------- Display function works started ---------------------
void printElement(stack < int > &st, stack < int > &helper) {
        while ( !helper.empty() ) {
                cout << helper.top() << " ";
                st.push(helper.top());
                helper.pop();
        }
}

void printHelp(stack < int > &st, stack < int > &helper) {
        while ( !st.empty() ) {
                helper.push(st.top());
                st.pop();
        }
}

void display(stack < int > &first, stack < int > &second) {
        if ( isEmpty(first, second) )
                cout << "Queue is empty" << endl;
        else {
                stack < int > test;
                cout << "Queue is : ";
                if ( !first.empty() && second.empty() ) {
                        printHelp(first, test);
                        printElement(first, test);
                } else if ( first.empty()  && !second.empty() ) {
                        printElement(test, second);
                        printHelp(test, second);
                } else {
                        printElement(test, second);
                        printHelp(test, second);

                        printHelp(first, test);
                        printElement(first, test);
                }
                cout << endl;
        }
}
// ------------------------- Display function works ended --------------------------------

int main()
{
        stack < int > first, second;
        enqueue(first, 6);
        enqueue(first, 3);
        enqueue(first, 9);

        display(first, second);
        cout << "First element is : " << firstElement << endl;
        cout << "Last element is : " << lastElement << endl << endl;

        int value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        display(first, second);
        cout << "First element is : " << firstElement << endl;
        cout << "Last element is : " << lastElement << endl << endl;

        enqueue(first, 2);
        enqueue(first, 8);

        display(first, second);
        cout << "First element is : " << firstElement << endl;
        cout << "Last element is : " << lastElement << endl << endl;

        value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        display(first, second);
        cout << "First element is : " << firstElement << endl;
        cout << "Last element is : " << lastElement << endl << endl;

        value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        value = dequeue(first, second);
        if ( value != -1 )
                cout << value << " is popped" << endl;

        display(first, second);
        cout << "First element is : " << firstElement << endl;
        cout << "Last element is : " << lastElement << endl << endl;

        return 0;
}
