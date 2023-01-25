// Deyber Castillo
// App de para clasificar peliculas por categorias con un dropdown

url = "https://api.themoviedb.org/3/" // URL base para las peticiones
api_key = "55a7b3e714660313cd57401445c3d938" // Token de acceso de Deyber Castillo
language = "es-ES" // Lenguaje de la API
image_language = "es,null" // Lenguaje de las imagenes
image_url = "https://image.tmdb.org/t/p/w500" // URL base para las imagenes
page = 1 // Pagina actual
namesGenres = [] // Arreglo de objetos con los nombres de las categorias

// Funcion que trae los nombres de las categorias o generos
function getMoviesGenre() {
  let url = "https://api.themoviedb.org/3/genre/movie/list?api_key=55a7b3e714660313cd57401445c3d938&language=es-ES"
  return fetch(url)
    .then(response => response.json())
    .then(data => data.genres)
}

// Llena la lista namesGenres de categorias con los nombres y ids de las categorias o generos
function fillNamesGeneres() {
  getMoviesGenre().then(data => {
    data.forEach(element => {
      namesGenres.push({ id: element.id, name: element.name })
    });
  })
}

// Llenar el checkbox con las opciones de categorias o generos
function fillDropdown() {
  let dropdown = document.getElementById("categorias")
  let option = document.createElement("option")
  option.value = ""
  option.text = "Todas las categorias"
  dropdown.add(option)
  getMoviesGenre().then(data => {
    data.forEach(element => {
      let option = document.createElement("option")
      option.value = element.id
      option.text = element.name
      dropdown.add(option)
    });
  }
  )
}

// Llamada a las funciones
fillDropdown() // Llenar el checkbox con las opciones de categorias o generos
fillNamesGeneres() // Llena la lista namesGenres de categorias con los nombres y ids de las categorias o generos

// Funcion trae desde el API las peliculas por categoria
function getMoviesByGenre(genre_id) {
  let url = "https://api.themoviedb.org/3/discover/movie?api_key=55a7b3e714660313cd57401445c3d938&language=es-ES&include_image_language=es,null&sort_by=popularity.desc&include_adult=false&include_video=false&page=" + page + "&with_genres=" + genre_id
  return fetch(url)
    .then(response => response.json())
    .then(data => data.results)
}

// Listar nombres de categorias por id
function getListNamesGenereByIds(genre_ids) {
  let names = []
  genre_ids.forEach(element => {
    names.push(namesGenres.find(x => x.id == element).name)
  });
  return names
}

// Llenar el main con id="movies" con las peliculas por categoria
function fillMovies(genre_id) {
  // limpiar el main con id="movies"
  document.getElementById("movies").innerHTML = ""
  // Usar createContextualFrame
  const data = getMoviesByGenre(genre_id)
  data.then(data => {
    data.forEach(element => {
      const namesGenres = getListNamesGenereByIds(element.genre_ids)
      const article = document.createRange().createContextualFragment(`
        <article>
            <div class="image-container">
                <img src="${image_url + element.poster_path}" alt="imagen">
            </div>
            <h2>${element.title}</h2>
            <span>${element.release_date}</span>
            <p>${element.overview}</p>
            <!-- Lista de categorias -->
            <h3>Categorias</h3>
            <ul>
            </ul>
        </article>
      `)
      const ul = article.querySelector("ul")
      namesGenres.forEach(element => {
        const li = document.createElement("li")
        li.innerHTML = element
        ul.appendChild(li)
      })
      document.getElementById("movies").appendChild(article)
    }
    )
  })
  document.getElementById("page").innerHTML = page
}

// Trae las series populares de TV desde el API
function getPopularTvShows() {
  // tv/popular
  let url = "https://api.themoviedb.org/3/tv/popular?api_key=55a7b3e714660313cd57401445c3d938&language=es-ES&include_image_language=es,null&page=" + page
  return fetch(url)
    .then(response => response.json())
    .then(data => data.results)
}

// Llenar el main con id="series" con las series populares de TV
function fillTvShows() {
  // TODO
  // limpiar el main con id="series"
  document.getElementById("series").innerHTML = ""
  // Usar createContextualFrame
  const data = getPopularTvShows()
  data.then(data => {
    data.forEach(element => {
      const article = document.createRange().createContextualFragment(`
        <article>
            <div class="image-container">
                <img src="${image_url + element.poster_path}" alt="imagen">
            </div>
            <h2>${element.name}</h2>
            <span>${element.first_air_date}</span>
            <p>${element.overview}</p>
        </article>
      `)
      document.getElementById("series").appendChild(article)
    }
    )
  })
}

// Funcion que trae las peliculas mas populares, cuando se carga la pagina
fillMovies('')
// Funcion que trae las series mas populares, cuando se carga la pagina
fillTvShows()

// Trae la pagina anterior de peliculas
function anterior() {
  if (page > 1) {
    page--
    let dropdown = document.getElementById("categorias")
    let genre_id = dropdown.value
    fillMovies(genre_id)
    fillTvShows()
  }
}

// Trae la pagina siguiente de peliculas
function siguiente() {
  page++
  let dropdown = document.getElementById("categorias")
  let genre_id = dropdown.value
  fillMovies(genre_id)
  fillTvShows()
}

// Filtrar peliculas por categoria
function filtrar() {
  page = 1
  let dropdown = document.getElementById("categorias")
  let genre_id = dropdown.value
  fillMovies(genre_id)
  fillTvShows()
}


const menuBtn = document.querySelector("header button");
const menu = document.querySelector("header nav");

menuBtn.addEventListener("click", () => {
  menu.classList.toggle("active");
});


