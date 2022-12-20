# Principe SOLID

`` SOLID est r�git par 5 r�gles qui permettent d'am�liorer la qualit� du code en POO :
1. **Single Responsibility Principle** Chaque code doit avoir une unique responsabilit�
2. **Open/Closed Principe** Les classes doivent �tre con�ues pour �tendre le code sans modifier le code existant.
3. **Liskov Substitution Pinciple** Les classes filles doivent pouvoir �tre utilis�es � la place des classes m�res sans erreurs.
4. **Interface Segregation Principle** Pas d'interfaces inutiles ou non utilis�es dans le code
5. **Dependency Inversion Principle** Les modules de haut niveau (ex: algorithmes) ne doivent pas d�pendre de ceux de bas niveaux, mais plut�t d'abstraction.
``

## S
`` Chacune de ces classes remplissent un r�le bien pr�cis et suivent donc bien l�ordre d�h�ritage et de propre responsabilit�.
La classe Grille permet d�avoir toutes les fonctions qui permettent le bon fonctionnement d�une quelconque grille (colonne x ligne).
La classe Main sert de menu pour choisir � quel jeu nous souhaitons jouer et donc initialise le jeu choisi.
La classe Morpionx h�rite de la Classe Grille, elle contient les m�thodes qui d�terminent qui est ce qui gagne.
La classe Puissance4 h�rite de la Classe Grille, elle contient les m�thodes qui d�terminent qui est ce qui gagne.``

## O
`` Au sein de notre code, comme nous n'avons pas impl�ment� de'interfaces, ceci n'est pas respect�.'``

## L
`` N'ayant que tr�s peu de classes (4 au total), ce principe n'est pas enti�rement respect�.
En effet, seul les classes Puissance4 et Morpionx h�ritent tous deux de la classe Grille `` 

## I
`` Nous n�avons pas d�interface car aucune de nos classes pr�sente des m�thodes virtual donc le choix de ne pas mettre d�interface �tait justifi�. Cependant, le principe reste tout de m�me respect� car on peut choisir d�emporter uniquement le jeu du morpion ou le jeu Puissance4, de plus toutes les m�thodes de nos classes sont utilis�es.``

## D
`` Le code ne respecte pas ce principe ``