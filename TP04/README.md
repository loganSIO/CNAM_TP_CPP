# Principe SOLID

`` SOLID est régit par 5 règles qui permettent d'améliorer la qualité du code en POO :
1. **Single Responsibility Principle** Chaque code doit avoir une unique responsabilité
2. **Open/Closed Principe** Les classes doivent être conçues pour étendre le code sans modifier le code existant.
3. **Liskov Substitution Pinciple** Les classes filles doivent pouvoir être utilisées à la place des classes mères sans erreurs.
4. **Interface Segregation Principle** Pas d'interfaces inutiles ou non utilisées dans le code
5. **Dependency Inversion Principle** Les modules de haut niveau (ex: algorithmes) ne doivent pas dépendre de ceux de bas niveaux, mais plutôt d'abstraction.
``

## S
`` Chacune de ces classes remplissent un rôle bien précis et suivent donc bien l’ordre d’héritage et de propre responsabilité.
La classe Grille permet d’avoir toutes les fonctions qui permettent le bon fonctionnement d’une quelconque grille (colonne x ligne).
La classe Main sert de menu pour choisir à quel jeu nous souhaitons jouer et donc initialise le jeu choisi.
La classe Morpionx hérite de la Classe Grille, elle contient les méthodes qui déterminent qui est ce qui gagne.
La classe Puissance4 hérite de la Classe Grille, elle contient les méthodes qui déterminent qui est ce qui gagne.``

## O
`` Au sein de notre code, comme nous n'avons pas implémenté de'interfaces, ceci n'est pas respecté.'``

## L
`` N'ayant que très peu de classes (4 au total), ce principe n'est pas entièrement respecté.
En effet, seul les classes Puissance4 et Morpionx héritent tous deux de la classe Grille `` 

## I
`` Nous n’avons pas d’interface car aucune de nos classes présente des méthodes virtual donc le choix de ne pas mettre d’interface était justifié. Cependant, le principe reste tout de même respecté car on peut choisir d’emporter uniquement le jeu du morpion ou le jeu Puissance4, de plus toutes les méthodes de nos classes sont utilisées.``

## D
`` Le code ne respecte pas ce principe ``