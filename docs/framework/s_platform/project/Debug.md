# Debug

## Profiler

Le profileur permet de tracer les objets d'une application de façon granulaire.
L'objectif est de pouvoir tracer des objets à certains moments de l'application
sans nécessairement tous les tracer.

Le fonctionnement du profileur se base essentiellement sur le concept de souscription.
Les objets sont abonnés au profileur avec des tags. Lorsqu'on veut tracer l'objets avec
un tag précis on vérifie si celui est abonné à ce tag.

```
Exemple 1
Obj A est abonné au profileur avec le tag INIT
Obj B est abonné au profileur avec le tag EXECUTE

Si on fait
profileur->trace(INIT, Obj A)
profileur->trace(INIT, Obj B)

On tracera seulement l'objet A
```

Le but de cette fonctionnalité est de tracer les applications qui effectue des traitements sur
beaucoup d'objet par exemple en infographie. Si tu veux investiguer certain problème lors de la phase
de rendu de l'application alors il ne faut pas tracer tous les objets sinon il y aura trop de bruit.
Mais c'est utile de tracer tous les objets lors de la phase d'initialisation parce que celle-ci peut
nous fournir des informations utiles concernant la phase de rendu.

```
Exemple 2

-- Création object graphique
Profileur->Subscribe(Carre1, "INIT", "RENDER")
Profileur->Subscribe(Carre2, "INIT")

-- Phase Initialisation
foreach Carre
    Profileur->Tracer(INIT)

Trace les deux carrés

-- Phase de rendu
foreach Carre
    Profileur->Tracer(RENDER)

Trace seulement Carre1

-- Action utilisateur
Profileur->Subscribe(Carre2, "RENDER")
Profileur->Unsubscribe(Carre1, "RENDER")

Prochaine pahse de rendu , le profileur trace seulement Carre2
```
