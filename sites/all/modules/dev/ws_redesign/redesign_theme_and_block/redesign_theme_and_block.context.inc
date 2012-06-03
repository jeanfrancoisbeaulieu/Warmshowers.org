<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function redesign_theme_and_block_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'authenticated_dashboard';
  $context->description = 'Dashboard page for logged-in users';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'wsmap-wsmap_expand_map_link' => array(
          'module' => 'wsmap',
          'delta' => 'wsmap_expand_map_link',
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'wsuser-wsuser_search_block' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_search_block',
          'region' => 'sidebar_first',
          'weight' => 1,
        ),
        'wsuser-wsuser_member_welcome_block' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_member_welcome_block',
          'region' => 'highlight',
          'weight' => 0,
        ),
        'wsuser-wsuser_member_recommendation' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_member_recommendation',
          'region' => 'highlight',
          'weight' => 1,
        ),
        'follow-site' => array(
          'module' => 'follow',
          'delta' => 'site',
          'region' => 'highlight',
          'weight' => 2,
        ),
        'views-recent_forum_topics-block_1' => array(
          'module' => 'views',
          'delta' => 'recent_forum_topics-block_1',
          'region' => 'highlight',
          'weight' => 3,
        ),
        'wsmap-wsmap_map' => array(
          'module' => 'wsmap',
          'delta' => 'wsmap_map',
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dashboard page for logged-in users');
  $export['authenticated_dashboard'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'everywhere';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-0' => array(
          'module' => 'locale',
          'delta' => 0,
          'region' => 'header',
          'weight' => 0,
        ),
        'menu-footer_menu' => array(
          'module' => 'menu',
          'delta' => 'footer_menu',
          'region' => 'footer',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['everywhere'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'everywhere_anon';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-anon_main_menu' => array(
          'module' => 'menu',
          'delta' => 'anon_main_menu',
          'region' => 'navigation',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['everywhere_anon'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'everywhere_auth';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-logged_in_main_menu' => array(
          'module' => 'menu',
          'delta' => 'logged_in_main_menu',
          'region' => 'navigation',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['everywhere_auth'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'profile_page_other';
  $context->description = 'Profile page as shown to other users (not self)';
  $context->tag = '';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
    'user_page' => array(
      'values' => array(
        'view' => 'view',
      ),
      'options' => array(
        'mode' => 'other',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'wsuser-wsuser_member_contact_location' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_member_contact_location',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'wsuser-wsuser_member_actions' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_member_actions',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Profile page as shown to other users (not self)');
  $export['profile_page_other'] = $context;

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'unauthenticated_front';
  $context->description = 'front page for unauthenticated users';
  $context->tag = '';
  $context->conditions = array(
    'language' => array(
      'values' => array(
        'en-working' => 'en-working',
      ),
    ),
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
    'user' => array(
      'values' => array(
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-15' => array(
          'module' => 'block',
          'delta' => 15,
          'region' => 'sidebar_first',
          'weight' => 0,
        ),
        'views-photo_contest-block_2' => array(
          'module' => 'views',
          'delta' => 'photo_contest-block_2',
          'region' => 'sidebar_second',
          'weight' => 0,
        ),
        'views-de434713ad5df48da12c8117a8e0ae3e' => array(
          'module' => 'views',
          'delta' => 'de434713ad5df48da12c8117a8e0ae3e',
          'region' => 'sidebar_second',
          'weight' => 1,
        ),
        'wsuser-wsuser_member_count_block' => array(
          'module' => 'wsuser',
          'delta' => 'wsuser_member_count_block',
          'region' => 'highlight',
          'weight' => 0,
        ),
        'views-map_slideshow-block_1' => array(
          'module' => 'views',
          'delta' => 'map_slideshow-block_1',
          'region' => 'content_top',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('front page for unauthenticated users');
  $export['unauthenticated_front'] = $context;

  return $export;
}