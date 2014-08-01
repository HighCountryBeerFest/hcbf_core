<div class="wrapper wrapper-blog">
  <div class="container">
    <div class="row">
      <div class="col-xs-12 col-md-9">
        <?php if (!empty($posts)): ?>
          <?php foreach ($posts as $post) { ?>
            <?php print render($post['title']); ?>
            <?php print render($post['body']); ?>
          <?php }; ?>
          <?php print theme('pager'); ?>
        <?php else: ?>
          <h1>There are no blog posts.</h1>
        <?php endif; ?>
      </div>
      <div class="col-xs-12 col-md-3">
        <?php print render(hcbf_buy_tickets_box(array('well'))); ?>

        <div class="well">
          <div class="page-header">
            <h2 class="text-center">Recent posts</h2>
          </div>

          <ul class="nav nav-pills nav-stacked">
            <?php if (!empty($recent_posts)): ?>
              <?php foreach ($recent_posts as $post) { ?>
                <?php print render($post['link']); ?>
              <? }; ?>
            <?php else: ?>
              <li><a href="#">No recent posts</a></li>
            <?php endif; ?>
          </ul>
        </div>

      </div>
    </div>
  </div>
</div>
