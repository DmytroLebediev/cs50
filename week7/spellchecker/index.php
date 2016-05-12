<!DOCTYPE html>

<html>
    <head>
        <title>hello</title>
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <form action="spellchecker.php">
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
        <div class="footer">
            <?php
                echo "Copyright &copy; 1991-".date("Y")." Lebediev";
            ?>
        </div>
    </body>
</html>