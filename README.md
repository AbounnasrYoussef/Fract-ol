# fract-ol

## 🎨 Objectif du projet

Le projet **fract-ol** a pour but de générer et d'afficher des **fractales** en temps réel à l’aide de la bibliothèque graphique **MiniLibX**.

Le but est de :
- Générer des images de fractales complexes (comme Mandelbrot ou Julia).
- Comprendre les nombres complexes, les itérations et les visualisations mathématiques.
- Apprendre à utiliser une librairie graphique en C.

---

## 📚 Fractales à implémenter (mandatory)

- **Mandelbrot**
- **Julia**
- **Burning Ship** (ou une autre si précisé)

Chaque fractale doit être interactive et bien rendue graphiquement.

---

## 🧩 Étapes du projet (Partie Mandatory)

### 1. **Initialisation de la fenêtre**
- Utiliser MiniLibX pour ouvrir une fenêtre graphique (généralement 800x800).
- Dessiner un pixel par pixel dans une image (`mlx_new_image` + `mlx_put_image_to_window`).

### 2. **Gestion des entrées utilisateur**
- Lire les arguments du programme :
  ```bash
  ./fractol mandelbrot
  ./fractol julia
  ./fractol burning_ship
