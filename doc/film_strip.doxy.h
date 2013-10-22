/**
 * @~english
 * @taomoduledescription{FilmStrip, Film strip and old movie effects}
 * <tt>import FilmStrip</tt> - Show video or other content in the frames of a 35mm film strip.@n
 *
 * This module also provides a GLSL shader to simulate defects commonly
 * found on old movies (color fading, lighting instabilities, scratches
 * and splotches), as well as as movie countdown animation that looks like
 * the sequence commonly used for 35mm movies.
 *
 * Here is an example (<a href="hello_strip.ddd">hello_strip.ddd</a>)
 * that re-uses the "Hello World" demo, bundled with
 * most versions of Tao Presentations.
 *
 * @include hello_strip.ddd
 * @image html HelloStrip.png "The Hello World demo playing on a film strip"
 *
 * To play a video with an "old movie" effect (<a href="old_video.ddd">old_video.ddd</a>):
 *
 * @include old_video.ddd
 *
 * @endtaomoduledescription{FilmStrip}
 *
 * @~french
 * @taomoduledescription{FilmStrip, Pellicule de film et effet «vieux film»}
 * <tt>import FilmStrip</tt> - Permet d'afficher des vidéos ou d'autres
 * contenus dans les cadres d'une pellicule 35mm.@n
 *
 * Ce module fournit également un shader GLSL qui simule
 * les effets du vieillissement des films photographiques (couleurs délavées,
 * scintillements, rayures et taches), et qui peut être appliqué à des vidéos
 * ou tout autre contenu. Également disponible : un compte à rebours animé qui
 * ressemble à la séquence communément utilisée au début des films 35mm.
 *
 * Voici un exemple (<a href="hello_strip.ddd">hello_strip.ddd</a>)
 * qui réutilise la démonstration "Hello World" fournie
 * avec la plupart des versions de Tao Presentations.
 *
 * @include hello_strip.ddd
 * @image html HelloStrip.png "La scène Hello World jouée sur une pellicule 35mm"
 *
 * Pour jouer une vidéo avec un effet vieilli (<a href="old_video.ddd">old_video.ddd</a>) :
 *
 * @include old_video.ddd
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
 * Example (<a href="old_movie.ddd">old_movie.ddd</a>):
 * @include old_movie.ddd
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
 * Exemple (<a href="old_movie_fr.ddd">old_movie_fr.ddd</a>):
 * @include old_movie_fr.ddd
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
@code
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
@endcode
 */
old_movie_shader_amount(Amount:real);


/**
 * @~english
 * Show an animated countdown as found at the beginning of some movies.
 *
 * The animation looks like the "SMPTE Universal Leader", commonly used from
 * the mid-60s for television and theatrical projection applications.
 * This effect is not meant to be a precise reproduction of the original test
 * sequence. Its purpose is just to suggest that a movie is about to begin.
 *
 * With the default parameters, the countdown goes from 8 to 2, each number
 * being shown during 1 second except number 2, which is shown for a very short
 * amount of time and followed by 2 seconds of black.
 *
 * The @ref FLNoiseAmount variable may be used to add some video noise.
 * @ref FLPopVolume controls the audio volume of the quick beep that is
 * normally heard when number "2" is shown.
 *
 * Example (<a href="countdown.ddd">countdown.ddd</a>):
 * @~french
 * Affiche un décompte animé similaire à celui utilisé au cinéma.
 *
 * L'animation ressemble à la séquence "SMPTE Universal Leader", couramment
 * utilisée à partir du milieu des années 60 à la télévision et dans les salles
 * de projection.
 * Cet effet ne prétend pas être une reproduction précise de la séquence
 * originale ; il est simplement fait pour suggérer qu'un film va commencer.
 *
 * Avec les paramètres par défaut, le décompte va de 8 à 2. Chaque chiffre
 * est affiché pendant une seconde, sauf le 2 qui apparaît durant un temps
 * très court et est suivi de deux secondes de noir.
 *
 * @p Start est la valeur de page_time à laquelle l'animation commence, par
 * défaut : 0.0.
 * @p Duration est la durée totale de l'animation, par défaut : 8.0.
 * Enfin, @p W et @p H sont la largeur et la hauteur du rectangle qui affiche
 * l'effet, par défaut : window_width et window_height, respectivement.
 *
 * Certains aspects sont configurables par des variables, avant d'appeler
 * l'effet.
 * La variable @ref FLNoiseAmount permet de superposer du bruit vidéo (de la
 * "neige"). Quant à @ref FLPopVolume, elle contrôle le volume audio du bip
 * qui est normalement émis lorsque le chiffre "2" est affiché.
 *
 * Exemple (<a href="countdown.ddd">countdown.ddd</a>):
 * @~
 * @include countdown.ddd
 * @since 1.001 (Tao 1.31)
 */
film_leader_countdown(Start:real, Duration:real, W:real, H:real);


/**
 * @~english
 * The amount of video noise (static noise) in @ref film_leader_countdown.
 * 0.0 is "no noise", 1.0 is "medium noise", higher values increase the amount of
 * noise.
 *
 * @~french
 * Quantité de bruit de fond vidéo (neige) dans @ref film_leader_countdown.
 * 0.0 signifie "pas de bruit", 1.0 correspond à un niveau de bruit moyen,
 * toute valeur supérieure augmente le bruit.
 * @~
 * @since 1.001 (Tao 1.31)
 */
FLNoiseAmount = 0.0;


/**
 * @~english
 * The audio volume of the short "pop" played when @ref film_leader_countdown reaches 2.
 * Possible values range from 0.0 (no pop) to 1.0 (normal volume of the
 * sound sample).
 *
 * If you set FLPopVolume to a non-zero value, you <b>must</b> import the
 * <tt>VLCAudioVideo</tt> module.
 * @~french
 * Le niveau de volume audio du "bip" joué lorsque @ref film_leader_countdown affiche 2.
 * Les valeurs possibles vont de 0.0 (pas de bip) à 1.0 (volume normal de
 * l'échantillon sonore).
 *
 * Si vous donnez une valeur non nulle à FLPopVolume, vous <b>devez</b>
 * importer le module <tt>VLCAudioVideo</tt>.
 * @~
 * @since 1.001 (Tao 1.31)
 */
FLPopVolume = 0.0;

/**
 * @}
 */
