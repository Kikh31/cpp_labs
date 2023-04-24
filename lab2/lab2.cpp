#include "iostream"
#include "stack.h"

using namespace std;

int main() {
    cout << "Stack\n"
            "Input max size of stack:\n";
    int stackSize;
    cin >> stackSize;
    Stack stack(stackSize);

    cout << "Stack created\n"
            "List of commands:\n"
            "/push <int>\n"
            "/pop\n"
            "/lenght\n"
            "/getTop\n"
            "/printStack\n"
            "/stop - to stop the program\n";

    while (true) {
        cout << ">>";
        string command;
        cin >> command;

        if (command == "/push") {
            int num;
            cin >> num;

            try {
                stack.push(num);
                cout << "Number " << num << " pushed\n";
            } catch (const char *er) {
                cout << er;
            }
        } else if (command == "/pop") {
            try {
                int ans = stack.pop();
                cout << "Number " << ans << " popped\n";
            } catch (const char *er) {
                cout << er;
            }
        } else if (command == "/lenght") {
                cout<<"Lenght of stack: "<<stack.lenght()<<'\n';
        } else if (command == "/getTop") {
            try {
                int top = stack.getTop();
                cout<<"Top: "<<top<<'\n';
            } catch (const char *er) {
                cout << er;
            }
        } else if (command == "/printStack") {
            try {
                stack.printStack();
                cout<<'\n';
            } catch (const char *er) {
                cout << er;
            }
        } else if(command == "/stop") {
            return 0;
        } else {
            cout<<"Unknown command\n";
        }

    }
}
