<!DOCTYPE html>

<html>
    <head>
        <title>hello</title>
        <link rel="stylesheet" href="styles.css">
        <link rel="shortcut icon" type="image/ico" href="/favicon.ico"/>
    </head>
    <body>
        <form action="spellchecker.php" method="post">
            <select name="selectedfile">
                <?php
                    $items = scandir("./texts");
                    foreach($items as $item)
                    {
                        if (is_file("./texts/$item"))
                        {
                            echo "<option value='$item'>$item</option>";
                        }
                    }
                ?>
            </select>
            <input type="submit" />
        </form>
        <?php
            require("footer.php");
        ?>
    </body>
</html>