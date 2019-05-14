
#include <iostream>
#include <list>
#include "stdio.h"
#include <set>
#include <map>
#include <iterator>
#include "circle.hpp"
#include <string>
#include "vec2.hpp"



int main() 
{ 
    
    std::list <unsigned int> list1; //unsigned: only 0 and positive numbers
//Aufgabe 3.2
    for (int i = 0; i < 10; i++){
        list1.push_back(rand() % 100 );
    }

    std::list <unsigned int>::iterator it1; 
    for(it1 = list1.begin(); it1 != list1.end(); ++it1) { //prints the whole list
        std::cout << '\t' << *it1; 
        std::cout << '\n'; 
    }

    int counter_outer = 0;
    int counter_inner = 0; 
    for(it1 = list1.begin(); it1 != list1.end(); ++it1) {
        counter_inner = 0;
        int a = *it1;
        std::list <unsigned int>::iterator it2;
        for(it2 = list1.begin(); it2 != list1.end(); ++it2) {
            int b = *it2;
            if (b != a){
                counter_inner++;
            }
            if (counter_inner == list1.size()-1){
                counter_outer++;
            }
        }
    }
    std::cout << "number of unique elements in list: " << counter_outer; //number of unique elements in list1
    std::cout << '\n'; 

    std::set<int> set1;
    for(int i = 0; i <= 100; i++ ){ //fills set1 with every number from 0 to 100
                set1.insert(i);
    }

    for(int i = 0; i <= 100; i++ ){ //deletes every number from set1 that also exists in list1
        for(it1 = list1.begin(); it1 != list1.end(); ++it1) {
            if (i == *it1){
                set1.erase(i);
            }
        }
    }
    
    for (std::set<int>::iterator it1=set1.begin(); it1!=set1.end(); ++it1){ //shows every entry of set1
	    std::cout << ' ' << *it1;
    }

//Aufgabe 3.3
    std::map<int, int> map1; 
    std::list<unsigned int>::iterator it3;
    int counter; 
    
        for(it3 = list1.begin(); it3 != list1.end(); ++it3) {
            counter = 0;
            int a = *it3;
            std::list<unsigned int>::iterator it4;
            for(it4 = list1.begin(); it4 != list1.end(); ++it4) {
                int b = *it4;
                if (b == a){
                    counter++;
                }
            }
            //std::pair<int, int>(*it3, counter));
            map1[*it3] = counter;
        }
    
    std::cout <<"\n" <<"\tNumber:\tFrequency:\n"; //alle elemente aus map1
    for (auto& i : map1){ // i = pair, map1 = map

        std::cout <<"\t" << i.first << "\t " << i.second <<"\n"; // first = key, second = value
    }

//Aufgabe 3.4

    std::string name; 
    Circle c1{450.0f,Vec2{200.0f,400.0f},Color{1.0f,0.0f,0.0f},"Circle1"};
    Circle c2{100.0f,Vec2{600.0f,400.0f},Color{0.0f,1.0f,0.0f},"Circle2"};
    Circle c3{30.0f,Vec2{200.0f,400.0f},Color{0.0f,0.0f,1.0f},"Circle3"};
    Circle c4{450.0f,Vec2{200.0f,300.0f},Color{1.0f,1.0f,0.0f},"Circle1"};

    std::set<Circle> circles;
       /* circles.insert(c1);
        circles.insert(c2);
        circles.insert(c3);
        circles.insert(c4);

     std::cout << "Please enter the name of your circle: \n";
    std::cin >> name ; 
   

    for(auto it1 = circles.begin(); it1 != circles.end(); it1++ ){
        if((*it1).get_name().compare(name)== 0){
            std::cout<<*it1;
        }
    }

*/



    return 0;
}