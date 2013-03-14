//Show / Hide Settings view
var btnSettings = document.querySelector("#settings-btn");
var viewSettings = document.querySelector("#settings-view");
btnSettings.addEventListener ('click', function () {
    viewSettings.classList.remove('move-down');
    viewSettings.classList.add('move-up');
});
/*var btnCloseSettings = document.querySelector("#close-btn");
btnCloseSettings.addEventListener ('click', function () {
    viewSettings.classList.remove('move-up');
    viewSettings.classList.add('move-down');
});*/

//Go deeper
var viewList = document.querySelector("#list-view");
var viewDetails = document.querySelector("#details-view");
var viewListItem = document.querySelector("#appList a");
var btnBack = document.querySelector(".back-button");
viewListItem.addEventListener ('click', function () {
    viewList.className = 'left';
    viewDetails.className = 'left';
});
btnBack.addEventListener ('click', function () {
    viewList.className = 'right';
    viewDetails.className = 'right';
});
