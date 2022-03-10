/*

Liste de "Features":
- Utiliser une structure de donn�es qui vous permet d'ajouter dynamiquement des informations � l'inventaire
- La grandeur de l'inventaire doit �tre dynamique
- Pour la structure de donn�es, nous devons pouvoir:
	- ajouter
	- enlever
	- trier
	- trouver un item relatif � sa position
	- trouver un item relatif � son nom
	- avoir la quantit� d'items dans la structure
- Avoir une structure qui va repr�senter les items. Elle va avoir un nom et une valeur de vente
- On doit avoir une fonction qui permet d'ajouter un item al�atoire. Votre tech lead fournit ces informations sur l'al�atoire en C.
- Les designers veulent pouvoir choisir les noms d'items avec leurs valeurs respectives sans modifier le code. Ils vont vous fournir un fichier de type CSV(comma separated value)
	Lire le fichier. Votre tech lead fournit cette information � ce sujet
	Peupler une liste d'items possibles, s�par�e de l'inventaire, � partir du document. Cette liste sera utilis�e lorsque nous ajouterons des items � l'inventaire.

- Pour arriver � cette derni�re "feature", votre tech lead vous dit qu'une fonction getline a �t� impl�ment� dans 
	les laboratoires et que vous pouvez la ''copier-coller'' dans votre code. Il vous dit aussi que vous pouvez vous baser 
	sur du code dans ce labo afin de vous aider.





-- Dans votre Main --
Dans votre application en mode console, votre team lead veut que vous testiez toutes les fonctionnalit�s. 
	Vous devez alors, dans votre main:

		- Peupler la liste d'items
		- Ajouter l'item nomm� "fiole" dans l'inventaire
	- Peupler l'inventaire d'un nombre al�atoire d'items en consid�rant que la "fiole" a d�j� �t� ajout�. Choisir les autres items al�atoirement et les ajouter dans l'inventaire.
	- Imprimer dans la console les items dans l'inventaire
	- Trier la liste d'items dans l'inventaire relatif � leur valeur de vente
	- enlever l'item "fiole" en utilisant son nom.
	- Imprimer dans la console les items dans l'inventaire � nouveau.
*/