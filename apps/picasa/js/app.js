$(document).ready(function(){
  var json_Album_URI = "https://picasaweb.google.com/data/feed/base/"
    + "user/"       +   "frankpotente77"
    + "?alt="       +   "json"
    + "&kind="      +   "album"
    + "&hl="        +   "en_US"
    + "&fields="    +   "entry(media:group,id)"
    + "&thumbsize=" +   104;

  $.getJSON(json_Album_URI,
  function(data){
    $.each(data.feed.entry, function(i,item){
      //Thumbnail URL
      $.each(item.media$group.media$thumbnail, function(i,item){
        var album_thumb_URL = item.url;
        // $('#images').append("Album Thumbnail: " + album_thumb_URL + '<br />');
      });
      //Album Title
      var album_Title = item.media$group.media$title.$t;
      //$('#title').append("Album Title: " + album_Title + '<br />');
      //Album Description
      var album_Description = item.media$group.media$description.$t;
      //$('#images').append("Album Description: " + album_Description + '<br />');
      //Album ID
      var album_ID = item.id.$t;
      //Get Numerical ID from URL
      album_ID = album_ID.split('/')[9].split('?')[0];
      //$('#images').append("AlbumID: " + album_ID + '<br /><br />');

  var json_Photo_URI = "https://picasaweb.google.com/data/feed/base/"
      + "user/"       +   "frankpotente77"
      + "/albumid/"   +   album_ID
      + "?alt="       +   "json"
      + "&kind="      +   "photo"
      + "&hl="        +   "en_US"
      + "&fields="    +   "entry(media:group)"
      + "&thumbsize=" +   104;


  $.ajax({
    type: 'GET',
    url: json_Photo_URI,
    success : function(data){
      $.each(data.feed.entry, function(i,item){
        //$('#images').append("Album Photos: <br />");
        //Photo URL
        $.each(item.media$group.media$content, function(i,item){
            var photo_URL = item.url;
           // $('#images').append("Image Photo URL: " + photo_URL + '<br />');
            //$('#images').append('<img src="'+ photo_URL + '" />');
        });
        //Thumbnail URL
        var output = '<li><aside class="pack-end">';
        $.each(item.media$group.media$thumbnail, function(i,item){
            var photo_Thumb_URL = item.url;
          //var photo_Description = item.description.$t;
            output += '<img src="'+ photo_Thumb_URL + '"" /></aside>';
        });
        //Photo Title
        var photo_Title = item.media$group.media$title.$t;
        //$('#images').append("Image Photo_Title: " + photo_Title + '<br />');
        //Photo Description
        var photo_Description = item.media$group.media$description.$t;
        //$('#images').append("Image Photo Description: " + photo_Description + '<br /><br />');

        output += '<a href="#"><p>'+photo_Title+'</p>';
        if (photo_Description) { 
          output += '<p>'+photo_Description+'</p>'
        }
        output += '</a>';

        $('#images').append(output);
      });
    },
    dataType: 'json',
    async: false
    });

    });
  });
});