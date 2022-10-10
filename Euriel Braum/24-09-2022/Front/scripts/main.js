// Funcion que evalua si el usuario esta logueado, si no redirecciona a la pagina de login
function checkLogin() {
    var user = localStorage.getItem("user");
    /*
        user = {
            "auth_token": {
                "created_at": "Mon, 26 Sep 2022 22:00:22 GMT",
                "expires_at": "Tue, 27 Sep 2022 22:00:22 GMT",
                "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6NCwiZXhwIjoxNjY0MzE2MDIyLCJpYXQiOjE2NjQyMjk2MjIsInN1YiI6Iml2YW5yYW1pcmV6Iiwicm9sZSI6InVzZXIifQ.cix0OQ6AhN8R1sbhSmyopOmOUm9PU6So5STNfua13pM"
            },
            "email": "ivanrene10@gmail.com.com",
            "fullname": "Ivan Rene Ramirez Castro",
            "id": 4,
            "password": true,
            "role": "user",
            "username": "ivanramirez"
        }   
    */
    if (user == null) {
        window.location.href = "login.html";
    } else {
        user = JSON.parse(user);
        var now = new Date();
        var expires_at = new Date(user.auth_token.expires_at);
        if (now > expires_at) {
            localStorage.removeItem("user");
            window.location.href = "login.html";
        }
    }
}
checkLogin();