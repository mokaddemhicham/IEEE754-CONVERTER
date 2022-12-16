# IEEE754 CONVERTER
 
En informatique, l’IEEE 754 est une norme sur l'arithmétique à virgule flottante mise au point par le Institute of Electrical and Electronics Engineers. Elle est la norme la plus employée actuellement pour le calcul des nombres à virgule flottante avec les CPU et les FPU. La norme définit les formats de représentation des nombres à virgule flottante (signe, mantisse, exposant, nombres dénormalisés) et valeurs spéciales (infinis et NaN), en même temps qu’un ensemble d’opérations sur les nombres flottants. Il décrit aussi cinq modes d'arrondi et cinq exceptions (comprenant les conditions dans lesquelles une exception se produit, et ce qui se passe dans ce cas).[[Wikipedia](https://fr.wikipedia.org/wiki/IEEE_754)].
## Format général
Un nombre flottant est formé de trois éléments : la mantisse, l'exposant et le signe. Le bit de poids fort est le bit de signe : si ce bit est à 1, le nombre est négatif, et s’il est à 0, le nombre est positif. Les e bits suivants représentent l'exposant biaisé (sauf valeur spéciale), et les m bits suivants (m bits de poids faible) représentent la mantisse.
## Format simple précision (32 bits)
Un nombre flottant simple précision est stocké dans un mot de 32 bits : 1 bit de signe, 8 bits pour l'exposant et 23 pour la mantisse.  
  
![](https://media.geeksforgeeks.org/wp-content/uploads/Single-Precision-IEEE-754-Floating-Point-Standard.jpg)  
