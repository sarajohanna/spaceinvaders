//
//  questions.hpp
//  spaceinvaders
//
//  Created by Sara Lindström on 2017-01-09.
//  Copyright © 2017 Sara Lindström. All rights reserved.
//

#ifndef questions_hpp
#define questions_hpp

#include <stdio.h>


// 1. enum SPRITES, används den endast till att räkna ut antal sprites (för ladda och rita)?
// 2. Varför en setCoords-funktion i Ship men inte i Aliens, där sätts de direkt i konstruktorn, varför inte göra på samma sätt?
// 3. Är det rimligast att ha collide-funktionen i world? Behövs det en collide för bullets och en för bombs? Hur kommer man åt bullets radie i world? Aliens går ju bra.
// 4. När du skapar Aliens i loopen anropar du konstruktorn med: Alien{coordAlien}, men det funkar också med Alien(coordAlien). Varför har du måsvingar och vilket är rätt/bäst/standard?
// 5. Måste man skriva Alien() = default; när man använder en (icke default) constructor också? Jag gjorde inte det först och då fungerade det inte. Har inte sett det förut.
// 6. Hur anväder man måsvingarna, skriver man dom på samma rad eller inte, t.ex när man definierar en funktion. Är det skillnad när man skapar class, struct, enum?




//Kollision med alien
//När du ska kolla krock: varje Alien har en mittpunkt och en radie. Tänk dig att radien gör en cirkel runt monstret. Kolla avståndet mellan kulan och mittpunkten på monstret. Om det är mindre än radien är den innanför cirkeln. Då har du en krock.
//Sphere collision kallas de
//Timer för bullets (och ev alien movements?)





//Bullets radie kommer du åt via en getfunktion tex
//Kollisioner kollas i world för alla objekt
//Alien()=default är samma som att skriva ={}
//Om du inte har skapat nån annan konstruktor kommer en defaultkonstruktor skapas åt dig
//Om du har skapat en konstruktor med inparam måste du skapa en defaultkonstruktor om den behövs nånstans
//Tex om du addar objekt via defaultkonstruktor i en vektor
//Måsvingarna skriver du som du vill men håll det konsekvent



#endif /* questions_hpp */
