<!DOCTYPE html>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta name="viewport" content="width=device-width, initial-scale=1.0" />
<title>CID Assignment</title>

<!--
CID Name Assignment
The user can select from three descriptions of pictures using radio buttons. Once submitted, the data will be sent to the server thru a GET for processing and return a page with the selected picture. Pick a theme and be creative! You can get a free, open source images from Wikimedia Images (see the link in Resources section.) Use CSS to create a pleasing presentation. Submit a link to a Github repository that contains the 2 files (an HTML and a PHP file) for this project. See the rubric below for grading criteria.
What objectives are you demonstrating?
(place here)
--> 

<style>


</style>

</head>
<body>

<?php
    if(isset($_GET["pic"])) {$pic = $_GET["pic"]; } else {$pic = ""; }
    if($pic == "car")
        {
            print
            "<body>
			<h1>Car</h1>
            <img src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Ftse3.mm.bing.net%2Fth%3Fid%3DOIP.VULsR6qyw_mkfi7EcKye9wHaD4%26pid%3DApi&f=1' />
            </body>"
        ;}
    if($pic == "truck")
        {
            print
            "<body>
			<h1>Truck</h1>
            <img src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.9to5carwallpapers.com%2Fwp-content%2Fuploads%2F2014%2F02%2FVolvo-Truck-Hd-Wallpapers.jpg&f=1&nofb=1'>
            </body>"
        ;}
    if($pic == "motorcycle")
        {
            print
            "<body>
			<h1>Motor Cycle</h1>
            <img src='https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.revzilla.com%2Fblog_content_image%2Fimage%2F50778%2Fredline_hero%2Fhonda-003.jpg&f=1&nofb=1'>
            </body>"
        ;}
?>
</body>
</html>