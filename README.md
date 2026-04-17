# Elektrokruh
Scripty (a jiné věci) pro kroužek Elektrotechniky SVČ Rosice.

Složka "Button" obsahuje kód script pro tlačítko, který jde přidat do jakéhokoliv scriptu.

Složka "Scripty Arduino" obsahuje scripty a zapojení prací, které jsme v minulosti dělali.
- všechny rezistory zapojené s LED diodami jsou 470 ohmů, protože nižší nemáme, ale můžete použít jakékoli rezistory od 220 ohmů výše (čím blíž k 220 ohmům, tím víc budou LEDky svítit)
- někdy se může stát, že piny nejsou správně rozdělené ve scriptu, ale jejich čísla se vždy dají přepsat v int proměnných nahoře (před voláním funkce setup())
- fyzické pull-up rezistory (zapojené od tlačítka do GND) mají vždy 10K ohmů, a v setupu navíc voláme interní pull-up rezistory Arduino boardu
- všechny scripty jsou zapojené na Arduino Uno R3, ale nejsou nijak robustní množstvím pinů, ani náročné, takže se dají zapojit i na jiných boardech
