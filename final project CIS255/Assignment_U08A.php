<!DOCTYPE html>
<html>
<head>
<link href="dog.css" rel="stylesheet" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title></title>

<!--
Ian Lorimer Assignment U0A
-->

</head>
<body>
    <!--Creates headings-->
    <div class="header">
    <h1>Pic-a-Pic</h1>
    </div>
    <!--Page Text-->
    <h2>Pic-a-Pic Has Gone to the Dogs</h2>
    <h2>Who let the dogs out?</h2>
    <!--Creates page images-->
    <img class="resize" src="https://astrokennels.files.wordpress.com/2015/08/befunky-collage.jpg" />
    <img class="resize2" src="https://theloveddog.com/wp-content/uploads/2016/12/dog-using-laptop-computer.jpg" />
    <p>Hey Dawg, make your choice:</p>
    <div class="output">
        <!--Creates input fields-->
        <form method="get" action="picapic.php">
            <input type="radio" id="pic1" name="pic" value="https://upload.wikimedia.org/wikipedia/commons/thumb/2/21/Dog_In_The_Grass.jpg/1280px-Dog_In_The_Grass.jpg">Dog in the Grass
            <input type="radio" id="pic2" name="pic" value="https://upload.wikimedia.org/wikipedia/commons/thumb/6/64/Chihuahua_puppy_-_Flickr_-_Jose_Antonio_Tovar.jpg/1280px-Chihuahua_puppy_-_Flickr_-_Jose_Antonio_Tovar.jpg">Chihuahua Puppy
            <input type="radio" id="pic3" name="pic" value="https://upload.wikimedia.org/wikipedia/commons/7/74/Cantabrian_Water_Dog.jpg">Cantabrian Water Dog
            <br />
            <br />
            <input id="button" type="submit" value="Fetch">
        </form>
    </div>
</body>
</html>