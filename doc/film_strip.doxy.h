/**
 * @~english
 * @taomoduledescription{FilmStrip, Film strip and old movie effects}
 *
 * Show video or other content in the frames of a 35mm film strip.
 * This module also provides a GLSL shader to simulate defects commonly
 * found on old movies (color fading, lighting instabilities, scratches
 * and splotches).
 *
 * Here is an example (<a href="hello_strip.ddd.txt">hello_strip.ddd</a>)
 * that re-uses the "Hello World" demo, bundled with
 * most versions of Tao Presentations.
 *
 * @include "hello_strip.ddd.txt"
 * @image html HelloStrip.png "The Hello World demo playing on a film strip"
 *
 * @endtaomoduledescription{FilmStrip}
 *
 * @~french
 * @taomoduledescription{FilmStrip, Pellicule de film et effet «vieux film»}
 *
 * Permet d'afficher des vidéos ou d'autres contenus dans les cadres d'une
 * pellicule 35mm. Ce module fournit également un shader GLSL qui simule
 * les effets du vieillissement des films photographiques (couleurs délavées,
 * scintillements, rayures et taches), et qui peut être appliqué à des vidéos
 * ou tout autre contenu.
 *
 * Voici un exemple (<a href="hello_strip.ddd.txt">hello_strip.ddd</a>)
 * qui réutilise la démonstration "Hello World" fournie
 * avec la plupart des versions de Tao Presentations.
 *
 * @include "hello_strip.ddd.txt"
 * @image html HelloStrip.png "La scène Hello World jouée sur une pellicule 35mm"
 *
 * @endtaomoduledescription{FilmStrip}
 *
 * @~
 * @{
 */

/**
 * @~english
 * Draw something as a texture on a strip of 35mm film.
 *
 * @p Body is a piece of code that should create a texture of aspect ratio
 * (width/height) equal to 5/3. @a film_strip draws a wavy ribbon that looks
 * like a strip of 35mm film, and applies the texture repeatedly onto the strip.
 * @p YShift is used to translate the texture pattern on the strip, so that
 * it is easy to give the appearance that the strip is rolling by supplying
 * a value that changes with time.
 *
 * See the main page of this module's documentation for an example.
 *
 * @~french
 * Dessine une texture sur une bande de film 35mm.
 *
 * @p Body est un bloc de code qui doit créer une texture de rapport largeur
 * sur hauteur égal à 5/3. @a film_strip dessine un ruban ondulé qui ressemble
 * à un morceau de pellicule 35mm, et applique la texture de manière répétée
 * sur le ruban.
 * Un translation de @p YShift pixels est effectuée sur la texture, de sorte
 * qu'il est facile de simuler l'apparence d'un ruban qui défile en faisant
 * varier @p YShift en fonction du temps.
 *
 * Un exemple d'utilisation est donné sur la page principale du module.
 */
film_strip(YShift:real, Body);

/**
 * @}
 */
