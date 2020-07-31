/*
   ad-hoc > implementation
   difficulty: easy
   date: 06/Apr/2020
   by: @brnpapa
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
   map<string, string> msg;
   msg["brasil"] = "Feliz Natal!";
   msg["alemanha"] = "Frohliche Weihnachten!";
   msg["austria"] = "Frohe Weihnacht!";
   msg["coreia"] = "Chuk Sung Tan!";
   msg["espanha"] = "Feliz Navidad!";
   msg["grecia"] = "Kala Christougena!";
   msg["estados-unidos"] = "Merry Christmas!";
   msg["inglaterra"] = "Merry Christmas!";
   msg["australia"] = "Merry Christmas!";
   msg["portugal"] = "Feliz Natal!";
   msg["suecia"] = "God Jul!";
   msg["turquia"] = "Mutlu Noeller";
   msg["argentina"] = "Feliz Navidad!";
   msg["chile"] = "Feliz Navidad!";
   msg["mexico"] = "Feliz Navidad!";
   msg["antardida"] = "Merry Christmas!";
   msg["canada"] = "Merry Christmas!";
   msg["irlanda"] = "Nollaig Shona Dhuit!";
   msg["belgica"] = "Zalig Kerstfeest!";
   msg["italia"] = "Buon Natale!";
   msg["libia"] = "Buon Natale!";
   msg["siria"] = "Milad Mubarak!";
   msg["marrocos"] = "Milad Mubarak!";
   msg["japao"] = "Merii Kurisumasu!";

   string s;
   while (cin >> s) {
      if (msg.count(s)) cout << msg[s] << endl;
      else cout << "--- NOT FOUND ---" << endl;
   }   
   return 0;
}
