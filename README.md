# MSW_kek_csapat

## Program működése 
A program két fájl nevét várja paracssori paraméterként. Ezek tartalmazzák a játékosok adatait, amiket a program kiolvas és eltárol. A harcot az először megadott játékos kezdi, és addig okoznak sebzést egymás hp-ján ameddig egyikuknek el nem fogy.    
## Használat
1. Git letöltése, majd a cmd-ben navigáljon a kívánt mappába és ```git clone https://github.com/Teaching-ASD/MSW_kek_csapat.git``` parancs után letölti a kódot.
2. WSL (csak windows környezetben kell) és g++ letöltése után a cmd-ben a ```g++ -std=c++17 *cpp``` parancsot gépelje hogy leforduljanak a fájlok.
3. A játékosok adatai egy fájlban tárolandók amit képes a c++ text fájlként beolvasni és előre meghatározott json formátumban tárolja az adatokat. 
Elfogadott formátum:<br/>
```
{
    "name" : "PlayerName",
    "hp" : 50,
    "dmg" : 10
}
```
4. ```./a.out argumentumlista``` a két játékost az argumentumlistában lehet megadni késöbb nem pl: ```./a.out ```