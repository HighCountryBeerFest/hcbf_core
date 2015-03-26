<div id="current-year-wrapper" class="wrapper jumbotron">
  <div class="container">

    <div class="row">
      <div class="col-xs-12">
        <h1>Join us on August 29<sup>th</sup>, 2015 for 8<sup>th</sup> annual High Country Beer Fest in Boone, NC.</h1>
        <p class="lead">Check back later for more information.</p>
      </div>
    </div>
  </div>

</div>



<div id="getting-there-wrapper" class="wrapper" style="display:none">
  <div class="container">

    <div class="row">
      <div class="col-xs-12">
        <div class="jumbotron">
          <h1>Join us for the 2015 High Country Beer Fest</h1>
          <p class="lead">Check back later for more information.</p>
        </div>
      </div>
    </div>

    <div class="row">
      <div class="col-xs-12 col-sm-3">
        <?php //print render(hcbf_the_festivities_box()); ?>
        <hr />
        <?php print theme('hcbf_breweries_on_sale', array('classes' => 'well')); ?>
      </div>

      <div class="col-xs-12 col-sm-9">

        <div class="container-fluid">

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h1>The festival is this Saturday! What should I bring?</h1>
              </div>
            </div>
          </div>

          <div class="row">
            <div class="col-xs-12 col-md-4">
              <div class="text-center">
                <i class="icon fa fa-check-square fa-5x"></i>
              </div>
              <div class="text-center">
                <h2>Your ID</h2>
              </div>
              <p class="lead">Remember to bring your ID, we check everyone's at the gate. We won't let you in if you don't have it or if you're under 21.</p>
            </div>

            <div class="col-xs-12 col-md-4">
              <div class="text-center">
                <i class="icon fa fa-money fa-5x"></i>
              </div>
              <div class="text-center">
                <h2>Cash</h2>
              </div>
              <p class="lead">Most of our vendors won't have access to the internet during the festival, so cash is the way to go. It makes it easier for everyone.</p>
            </div>

            <div class="col-xs-12 col-md-4">
              <div class="text-center">
                <i class="icon fa fa-thumbs-up fa-5x"></i>
              </div>
              <div class="text-center">
                <h2>A good attitude</h2>
              </div>
              <p class="lead">We're all here to have fun and enjoy ourselves, the music, the food and the beer.</p>
              <p class="lead">So be cool.</p>
            </div>
          </div>

          <div class="row">
            <div class="col-xs-12">
              <div class="page-header">
                <h1>How will I get there and back?</h1>
              </div>
            </div>
          </div>

          <div class="row">
            <div class="col-xs-12 col-sm-6">
              <h3>Take the shuttle from campus</h3>
              <p>The folks at River and Earth Adventures will have shuttle service from 2:00pm to 8:00pm going from the Raley Parking lot on Appalachian State University's campus to the Fairgrounds.</p>
              <p>We have a limited amount of seating on the buses.</p>
              <iframe
                width="100%"
                height="300"
                frameborder="0" style="border:0"
                src="https://www.google.com/maps/embed/v1/place?key=AIzaSyAcBExT7Gf5b1qYZH5r_SLBMNtmsGe1O_8
                &q=Asu+Raley+Hall+Traffic+Circle+NC&zoom=13">
              </iframe>
            </div>
            <div class="col-xs-12 col-sm-6">
              <h3>Take the shuttle from your hotel</h3>
              <p>If you're staying at the Country Inn or La Quinta our friends at the Mountain Alliance will come and pick you up starting at 2:00pm.</p>
              <p>Please do not park here if you are not staying at the hotels.</p>

              <h3>Get a designated driver</h3>
              <p>This is your best bet, designated driver tickets are only $10 and can make getting to and from the festival a lot safer.</p>

              <h3>Take a taxi</h3>
              <p>Tipsy Taxi is providing FREE rides anywhere in Boone.</p>

              <h3>Get a tow</h3>
              <p>Live in Boone? Bill's will tow your car and up to 4 people anywhere within the town limits for free.</p>
            </div>
          </div>

        </div>

      </div>

    </div>
  </div>
</div>
    
<div id="video-wrapper" class="wrapper inverse-wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-sm-8">
        <div class="video-wrapper">
          <iframe src="//player.vimeo.com/video/95663874" width="100%" height="420" frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen></iframe>
        </div>
      </div>
      <div class="col-xs-12 col-sm-4">
        <h1 class="heading">The High Country Beer Fest is a celebration of craft beer from around the region and the world.</h1>
        <p>Come sample outstanding beers and delicious food in the beautiful high country of North Carolina. Educational seminars will cover aspects of beer tasting, brewing, and food pairing.</p>
      </div>
    </div>
  </div>
</div>

<div id="about-wrapper" class="wrapper">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-md-6">
        <?php print theme('hcbf_breweries_registration'); ?>
      </div>
      <div class="col-xs-12 col-md-6">
        <?php print theme('hcbf_sponsor_registration'); ?>
      </div>
    </div>
  </div>
</div>

