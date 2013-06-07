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
 * To play a video with an "old movie" effect:
 *
 * @include "old_video.ddd.txt"
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
 * Pour jouer une vidéo avec un effet vieilli :
 *
 * @include "old_video.ddd.txt"
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
 * @~english
 * Make the current texture look like an old movie.
 *
 * This function activates a GLSL fragment shader. You may use
 * @ref old_movie_shader_amount to define the overall amount of the effect,
 * or you may use @a shader_set to define parameters individually. See
 * the below example or @ref old_movie_shader_amount for details on what can
 * be set.
 *
 * Example (<a href="old_movie.ddd.txt">old_movie.ddd</a>):
 * @include "old_movie.ddd.txt"
 *
 * @~french
 * Modifie la texture courante pour la faire ressembler à un vieux film.
 *
 * Cette fonction active un fragment shader GLSL. Vous pouvez utiliser
 * @ref old_movie_shader_amount pour définir le niveau global de l'effet, ou
 * bien appeler @a shader_set pour donner la valeur de chacun des paramètres.
 * Voyez l'exemple ci-dessous ainsi que la documentation de
 * @ref old_movie_shader_amount pour plus de détails sur ces paramètres.
 *
 * Exemple (<a href="old_movie_fr.ddd.txt">old_movie_fr.ddd</a>):
 * @include "old_movie_fr.ddd.txt"
 */
old_movie_shader();

/**
 * @~english
 * Define the amount of @ref old_movie_shader effect.
 * Equivalent to:
 *
 * @~french
 * Définit le niveau d'effet de @ref old_movie_shader.
 * Équivalent à:
 * @~
 * @code
    OldMovieAmount := Amount
    shader_set time := page_time mod 1000
    shader_set flicker := 0.1 * OldMovieAmount
    shader_set lightvariance := 0.05 * OldMovieAmount
    shader_set blackandwhite := 1.0 * OldMovieAmount
    shader_set oversaturation := 0.3 * OldMovieAmount
    shader_set vignette := 1.0 * OldMovieAmount
    shader_set scratches := 0.5 * OldMovieAmount^4
    shader_set scratchsize := 8, 200
    shader_set splotches := 200 * OldMovieAmount^8
 * @endcode
 */
old_movie_shader_amount(Amount:real);

/**
 * @}
 */
