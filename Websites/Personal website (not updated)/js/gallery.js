// Select all image elements on the page
const images = document.querySelectorAll('img');
const focused = document.getElementById("focused");
const focused_image = document.getElementById("focused-image");


// On click do something
images.forEach((img) => {
    img.addEventListener('click', () => {
        let full_resolution = img.src.replace("images-preview/", "").replace("_preview", "");

        focused_image.src = full_resolution;
        focused.classList.add("show");

        console.log('Image clicked:', full_resolution);
    });
});

focused.addEventListener('click', () => {
    focused.classList.remove("show");
})