#include <iostream>
#include <set>
#include "eqTriangle.h"
#include "parallelogram.h"

using namespace std;

struct comp {
    bool operator() (const Figure* a, const Figure* b) {
        return a->mass() < b->mass();
    }
};

int main() {
    set<Figure*, comp> set;
    cout << "Add figures:\n"
            "1.Equilateral triangle\n"
            "2.Parallelogram\n"
            "0.Finish adding\n";

    while (true) {
        int key;
        cout<<">>";
        cin>>key;

        if(key == 0) {
            break;
        } else if(key == 1) {
            set.insert(new eqTriangle());
        } else if(key == 2) {
            set.insert(new parallelogram());
        } else {
            cout<<"Unknown parameter\n";
        }
    }



    cout << "Functions:\n"
            "1.Show figures\n"
            "2.Total square\n"
            "3.Total perimeter\n"
            "4.Center of mass\n"
            "5.Total memory\n"
            "0.End\n";

    while (true) {
        int key;
        cout<<">>";
        cin>>key;

        if(key == 0) {
            break;
        } else if(key == 1) {
            for(auto x : set) {
                x->draw();
            }
        } else if(key == 2) {
            double sum = 0;
            for(auto x : set) {
                sum += x->square();
            }
            cout<<"Total square = "<<sum<<'\n';
        } else if(key == 3) {
            double sum = 0;
            for(auto x : set) {
                sum += x->perimeter();
            }
            cout<<"Total perimeter = "<<sum<<'\n';
        } else if(key == 4) {
            CVector2D cMass;
            double sumX = 0, sumY = 0, count = 0;
            for(auto x : set) {
                sumX += x->position().x;
                sumY += x->position().y;
                count++;
            }
            cMass.x = sumX / count;
            cMass.y = sumY / count;

            printf("enter of Mass: O(%f;%f)\n", cMass.x, cMass.y);
        } else if(key == 5) {
            double sum = 0;
            for(auto x : set) {
                sum += x->size();
            }
            cout<<"Total memory = "<<sum<<'\n';
        } else {
            cout<<"Unknown parameter\n";
        }
    }
}
