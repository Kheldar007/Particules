Projet particules
Isabelle Muller
M1 ISI
Janvier 2015


TODO :
- Image2Grey::I2G_smoothing
- GradientSobel::GradientSobel
- CsgTree::CT_load
- CsgTree::CT_save


Comment faire pour pouvoir écrire V = 0.5f * V ?
-> En mettant des operateurs binaires non-membres de la classe.

Qu'impliquerait d'ecrire le seuillage dans Image2D <T> ?
Comment contourner le probleme ?
-> Il y aurait un probleme au niveau du type il faut ecrire la fonction dans
Image2Grey.
