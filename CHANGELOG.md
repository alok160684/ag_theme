# Changelog

All notable changes to the AG Theme project will be documented in this file.

The format follows a simple release-based changelog structure inspired by Keep a Changelog and Semantic Versioning.

---

## [1.0.0] - 2026-04-28

### Added

#### Drupal Theme Foundation

- Added custom Drupal theme structure for `ag_theme`.
- Added `ag_theme.info.yml` with Drupal 10/11 support.
- Set base theme to `mercury`.
- Added root-level `logo.svg`.
- Added `ag_theme.libraries.yml` for CSS and JavaScript registration.
- Added `ag_theme.theme` for preprocess logic and dynamic theme behavior.

#### Theme Settings UI

- Added custom theme settings form in `includes/theme-settings.inc`.
- Added default theme settings in `config/install/ag_theme.settings.yml`.
- Added schema support for theme settings.
- Added settings for:
  - Logo visibility
  - Logo upload
  - Primary color
  - Secondary color
  - Layout width
  - Body font family
  - Heading font family
  - Base font size
  - Google Font selection
  - Google Font heading usage
  - Dark mode toggle
  - Dark background color
  - Dark text color

#### Dynamic Styling

- Added dynamic CSS variables from theme settings.
- Added dynamic color variables.
- Added dynamic layout width variable.
- Added dynamic typography variables.
- Added Google Font loading from selected theme setting.
- Added default logo fallback and uploaded logo override support.

#### Component Library

- Added Mercury-style component structure under `components/`.
- Added components:
  - Header
  - Footer
  - Hero
  - Card
  - Grid
  - Section
  - Button
  - Media
  - Text
  - Two-column
  - Container
  - Accordion
  - Tabs
  - Banner
  - Alert
  - Breadcrumb
  - Modal

#### Component Stories

- Added initial component story files:
  - `components/hero/hero.stories.yml`
  - `components/card/card.stories.yml`
  - `components/banner/banner.stories.yml`

#### Drupal Templates

- Added base theme templates:
  - `templates/page.html.twig`
  - `templates/node.html.twig`
  - `templates/block.html.twig`
  - `templates/region.html.twig`
  - `templates/field.html.twig`
  - `templates/menu.html.twig`
  - `templates/html.base.twig`

#### Page Layout Templates

- Added layout page templates:
  - `templates/layout/page--full.html.twig`
  - `templates/layout/page--sidebar.html.twig`
  - `templates/layout/page--landing.html.twig`

#### Layout Builder Support

- Added `ag_theme.layouts.yml`.
- Added Layout Builder layouts:
  - AG One column
  - AG Two column
  - AG Three column
- Added layout templates:
  - `layouts/one-column/one-column.html.twig`
  - `layouts/two-column/two-column.html.twig`
  - `layouts/three-column/three-column.html.twig`

#### JavaScript Behaviors

- Added Drupal behavior-based JavaScript files:
  - `js/components/accordion.js`
  - `js/components/tabs.js`
  - `js/components/modal.js`
- Registered component scripts in `ag_theme.libraries.yml`.

#### SCSS Architecture

- Added SCSS source structure.
- Added main SCSS entry file:
  - `scss/theme.scss`
- Added SCSS variables file:
  - `scss/base/_variables.scss`

#### Frontend Build System

- Added `package.json` for frontend build tooling.
- Added Sass compiler scripts.
- Added PostCSS support.
- Added Autoprefixer support.
- Added cssnano production optimization.
- Added Browserslist configuration.
- Added Stylelint configuration.
- Added Prettier configuration.
- Added frontend build documentation.

#### Documentation

- Added complete theme documentation:
  - `THEME_DOCUMENTATION.md`
- Added frontend build documentation:
  - `README-frontend-build.md`
- Added `README.txt`.

### Changed

- Updated `ag_theme.info.yml` to use Mercury as the base theme.
- Updated `ag_theme.libraries.yml` to register global styles, component styles, and component scripts.
- Updated `ag_theme.theme` to support:
  - Dynamic CSS variables
  - Logo handling
  - Google Font loading
  - Component script library attachment

### Notes

- Run `npm install` after pulling this release.
- Run `npm run build:css` for development CSS.
- Run `npm run build:css:min` for production CSS.
- Run `drush cr` after enabling or updating the theme.

---

## Future Improvements

Planned improvements may include:

- Complete remaining SCSS partials for all components.
- Add ESLint for JavaScript validation.
- Add Husky Git hooks for pre-commit checks.
- Add CI workflow for linting and frontend build validation.
- Add design token JSON files for colors, spacing, and typography.
- Add additional component stories and examples.
- Add accessibility testing notes and improvements.
