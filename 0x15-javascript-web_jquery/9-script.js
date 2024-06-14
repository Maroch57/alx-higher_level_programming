$(document).ready(function() {
    $.ajax({
        url: 'https://hellosalut.stefanbohacek.dev/?lang=fr',
        method: 'GET',
        success: function(response) {
            $('DIV#hello').text(response.hello);
        },
        error: function() {
            $('DIV#hello').text('Error fetching translation.');
        }
    });
});
