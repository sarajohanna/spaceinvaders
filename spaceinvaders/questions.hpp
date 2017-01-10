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




#endif /* questions_hpp */
